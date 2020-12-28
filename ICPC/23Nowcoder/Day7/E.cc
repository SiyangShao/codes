#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = (1 << 30);
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> sum(n + 1, 0), a(n + 1, 0);
  set<pair<int, int>> edg;
  vector<set<int>> g(n + 1);
  vector<set<pair<int, int>>> neg(n + 1);
  int pre = 0;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, v;
      cin >> u >> v;
      u = u ^ pre;
      v = v ^ pre;
      g[u].emplace(v);
      g[v].emplace(u);
    } else if (op == 2) {
      int u, v;
      cin >> u >> v;
      u = u ^ pre;
      v = v ^ pre;
      if (g[u].find(v) != g[u].end()) {
        g[u].erase(v);
      } else {
        auto it = neg[u].lower_bound({v, 0});
        assert(it != neg[u].end());
        sum[u] -= it->second;
        neg[u].erase(it);
      }
      if (g[v].find(u) != g[v].end()) {
        g[v].erase(u);
      } else {
        auto it = neg[v].lower_bound({u, 0});
        assert(it != neg[v].end());
        sum[v] -= it->second;
        neg[v].erase(it);
      }
    } else if (op == 3) {
      int x, c;
      cin >> x >> c;
      x = x ^ pre;
      c = c ^ pre;
      a[x] += c;
      sum[x] += c;
    } else {
      int x;
      cin >> x;
      x = x ^ pre;
      for (auto v : g[x]) {
        sum[x] += a[v];
        neg[x].emplace(v, a[v]);
      }
      g[x].clear();
      // for (auto [v, k] : neg[x]) {
      // sum[x] += k;
      // }
      // neg[x].clear();
      cout << sum[x] << "\n";
      pre = (int)(sum[x] % MOD);
      return;
    }
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