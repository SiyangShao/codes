#include <bits/stdc++.h>
using namespace std;
constexpr int N = 30;
struct lineB {
  array<int, N> pos;
  void add(int x) {
    for (int i = N - 1; i >= 0; --i) {
      if (!(x >> i))
        continue;
      if (!pos[i]) {
        pos[i] = x;
        break;
      }
      x ^= pos[i];
    }
  }
  int find_max() {
    int ans = 0;
    for (int i = N - 1; i >= 0; --i) {
      ans = max(ans, ans ^ pos[i]);
    }
    return ans;
  }
  void merge(lineB &ano) {
    for (auto i : ano.pos) {
      add(i);
    }
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<lineB> lb(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    lb[i].add(a[i]);
  }
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  int q;
  cin >> q;
  vector<vector<pair<int, int>>> ans(n);
  vector<pair<int, int>> ask(q);
  vector<int> output(q);
  for (int id = 0; auto &[u, v] : ask) {
    cin >> u >> v;
    u--, v--;
    ans[u].emplace_back(v, id++);
  }
  function<void(int, int)> build = [&](int u, int fa) {
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      build(v, u);
      lb[u].merge(lb[v]);
    }
  };
  function<void(int, int)> dp = [&](int u, int fa) {
    for (auto &[v, id] : ans[u]) {
      output[id] = lb[v].find_max();
    }
    int siz = (int)E[u].size();
    vector<lineB> pre(siz), aft(siz);
    pre[0] = lb[E[u][0]];
    for (int i = 1; i < siz; ++i) {
      pre[i] = lb[E[u][i]];
      pre[i].merge(pre[i - 1]);
    }
    aft[siz - 1] = lb[E[u][siz - 1]];
    for (int i = siz - 2; i >= 0; --i) {
      aft[i] = lb[E[u][i]];
      aft[i].merge(aft[i + 1]);
    }
    auto cur = lb[u];
    lineB base;
    for (int i = 0; i < siz; ++i) {
      auto v = E[u][i];
      if (v == fa)
        continue;
      auto bef = lb[v];
      lb[v].merge(cur);
      lb[u] = base;
      lb[u].add(a[u]);
      if (i != 0)
        lb[u].merge(pre[i - 1]);
      if (i + 1 != siz)
        lb[u].merge(aft[i + 1]);
      dp(v, u);
      lb[v] = bef;
    }
  };
  build(0, 0);
  dp(0, 0);
  for (auto i : output) {
    cout << i << "\n";
  }
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