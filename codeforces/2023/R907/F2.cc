#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
template <typename T> class FenwickTree {
public:
  FenwickTree(int n) : bits(n + 10, 0) {}
  void update(int i, T delta) {
    while (i < static_cast<int>(bits.size())) {
      bits[i] += delta;
      i += i & -i;
    }
  }
  [[nodiscard]] T query(int i) const {
    T sum = 0;
    while (i > 0) {
      sum += bits[i];
      i -= i & -i;
    }
    return sum;
  }

private:
  std::vector<T> bits;
};
auto solve() {
  int q;
  cin >> q;
  vector<vector<int>> query(q);
  int n = 1;
  for (auto &vec : query) {
    int t;
    cin >> t;
    int v;
    cin >> v;
    if (t == 1) {
      n++;
      vec = {t, v, n};
    } else {
      int x;
      cin >> x;
      vec = {t, v, x};
    }
  }

  vector<vector<int>> E(n + 1);
  vector<int> dfn(n + 1), lst(n + 1);
  vector<ll> ans(n + 1);
  FenwickTree<ll> fwt(n + 1);
  for (auto &vec : query) {
    int t = vec[0];
    int v = vec[1];
    int u = vec[2];
    if (t == 1) {
      E[v].emplace_back(u);
    }
  }
  int cnt = 1;
  function<void(int)> dfs = [&](int u) {
    dfn[u] = cnt++;
    for (auto v : E[u]) {
      dfs(v);
    }
    lst[u] = cnt;
  };
  dfs(1);
  dbg(dfn, lst);
  for (auto &vec : query) {
    int t = vec[0], v = vec[1], x = vec[2];
    if (t == 1) {
      dbg(x, dfn[x], lst[x]);
      assert(dfn[x] > 0 && dfn[x] <= n);
      assert(lst[x] > dfn[x] && lst[x] <= n + 1);
      ll val = fwt.query(dfn[x]);
      fwt.update(dfn[x], -val);
      fwt.update(lst[x], val);
    } else {
      assert(dfn[v] > 0 && dfn[v] <= n);
      assert(lst[v] > dfn[v] && lst[v] <= n + 1);
      fwt.update(dfn[v], x);
      fwt.update(lst[v], -x);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << fwt.query(dfn[i]) << " ";
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}