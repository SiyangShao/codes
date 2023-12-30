#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
map<vector<int>, int> vecHash;
vector<int> siz;
vector<vector<int>> vec;
int f(vector<int> &a) {
  if (vecHash.contains(a))
    return vecHash[a];
  int v = (int)vecHash.size();
  int sz = 1;
  for (auto i : a) {
    sz += siz[i];
  }
  siz.emplace_back(sz);
  vec.emplace_back(a);
  return vecHash[a] = v;
}
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  vector<pair<int, int>> edg;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edg.emplace_back(u, v);
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<int> h(n);
  set<int> st;
  function<void(int, int)> build = [&](int u, int fa) {
    vector<int> a;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      build(v, u);
      a.emplace_back(h[v]);
    }
    ranges::sort(a);
    h[u] = f(a);
    st.emplace(h[u]);
  };
  build(0, 0);
  vector<int> tree;
  for (int cnt = 1; cnt <= n; cnt++) {
    vector<int> tmp, nt;
    int flag = -1;
    function<void(int, int)> dfs = [&](int m, int i) {
      if (m == 0) {
        int x = f(tmp);
        nt.emplace_back(x);
        if (!st.contains(x)) {
          flag = x;
        }
        return;
      }
      while (i < (int)tree.size()) {
        int t = tree[i];
        if (m < siz[t]) {
          i++;
          continue;
        }
        tmp.emplace_back(t);
        dfs(m - siz[t], i);
        tmp.pop_back();
        if (flag != -1)
          return;
        i++;
      }
    };
    dfs(cnt - 1, 0);
    if (flag != -1) {
      dbg(cnt);
      int cur = 1;
      for (int i = 0; i < n - cnt; ++i) {
        cout << cur << " " << cur + 1 << "\n";
        cur++;
      }
      function<void(int, int)> dd = [&](int u, int t) {
        for (auto v : vec[t]) {
          int id = ++cur;
          cout << u << " " << id << "\n";
          dd(id, v);
        }
      };
      dd(cur, flag);
      return;
    }
    for (auto t : nt) {
      tree.push_back(t);
    }
    ranges::sort(tree);
  }
  for (auto [u, v] : edg) {
    cout << u << " " << v << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}
