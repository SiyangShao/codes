#include <bits/stdc++.h>
using namespace std;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edg;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v, i);
    edg.emplace_back(u, v, i);
  }
  vector<int> ans(m, 1);
  int k;
  cin >> k;
  vector<int> kill(k), nd_kill(n), has_kill(n);
  for (auto &i : kill) {
    cin >> i;
    i--;
    nd_kill[i] = 1;
  }
  priority_queue<tuple<int, int, int>> Q;
  for (auto &[u, v, id] : edg) {
    if (nd_kill[v] && !nd_kill[u]) {
      Q.emplace(id, u, v);
    }
  }
  while (!Q.empty()) {
    auto [id, u, v] = Q.top();
    Q.pop();
    if (has_kill[v])
      continue;
    ans[id] = 0;
    has_kill[v] = 1;
    nd_kill[v] = 0;
    for (auto [vv, iid] : E[v]) {
      if (iid > id)
        break;
      if (nd_kill[vv]) {
        Q.emplace(iid, v, vv);
      }
    }
  }
  for (auto i : kill) {
    if (!has_kill[i]) {
      cout << "NIE\n";
      return;
    }
  }
  cout << "TAK\n";
  for (int i = 0; i < m; ++i) {
    if (ans[i]) {
      cout << "N";
    } else {
      cout << "T";
    }
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