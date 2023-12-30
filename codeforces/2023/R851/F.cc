#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, int>>> E(n);
  vector<pair<int, int>> edg(n - 1);
  vector<int> deg(n);
  for (auto &[u, v] : edg) {
    cin >> u >> v;
    u--, v--;
    deg[u]++, deg[v]++;
  }
  // u-v XOR sum = x => p[u]  ^ p[v] = x, in which p[u] is the XOR sum from root
  // to u
  vector<int> p(n), vis(n);
  vector<tuple<int, int, int>> req(q);
  vector<int> critical;
  for (auto &[u, v, x] : req) {
    cin >> u >> v >> x;
    u--, v--;
    E[u].emplace_back(v, x);
    E[v].emplace_back(u, x);
  }
  int cnt = 0;
  vector<int> cur;
  function<bool(int)> dfs = [&](int u) {
    vis[u] = 1;
    cur.emplace_back(u);
    bool flag = true;
    if (deg[u] % 2 == 1)
      cnt++;
    for (auto [v, w] : E[u]) {
      if (!vis[v]) {
        p[v] = p[u] ^ w;
        flag = flag & dfs(v);
      } else {
        if ((p[v] ^ p[u]) != w) {
          return false;
        }
      }
    }
    return flag;
  };
  int sum = 0;
  vector<int> nxt;
  bool flag = false;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      cnt = 0;
      cur.clear();
      if (!dfs(i)) {
        cout << "No\n";
        return;
      }
      if (!flag && cnt % 2 == 1) {
        nxt = cur;
        flag = true;
      }
    }
    if (deg[i] % 2 == 1) {
      sum ^= p[i];
    }
  }
  if (!nxt.empty()) {
    for (auto i : nxt) {
      p[i] ^= sum;
    }
  }
  cout << "Yes\n";
  for (auto &[u, v] : edg) {
    cout << (p[u] ^ p[v]) << " ";
  }
  cout << "\n";
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