#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> vis(n), deg(n), vvis(n);
  set<pair<int, int>> st;
  queue<pair<int, int>> Q;
  int node = 0;
  vector<pair<int, int>> ans;
  function<void()> dp = [&]() {
    while (!Q.empty()) {
      auto [u, _] = Q.front();
      vvis[u] = 1;
      Q.pop();
      for (auto v : E[u]) {
        deg[v]--;
        if (deg[v] == 1) {
          Q.emplace(v, -1);
        }
      }
    }
    for (auto [u, v] : st) {
      if ((vvis[u] ^ vvis[v]) == 1) {
        if (vvis[u] == 1) {
          ans.emplace_back(v, u);
        } else {
          ans.emplace_back(u, v);
        }
      }
    }
  };
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    node++;
    deg[u] = (int)E[u].size();
    if (deg[u] == 1) {
      Q.emplace(u, E[u][0]);
    }
    for (auto v : E[u]) {
      if (u > v)
        st.emplace(u, v);
      if (vis[v])
        continue;
      dfs(v);
    }
  };

  for (int i = 0; i < n; ++i) {
    if (vis[i])
      continue;
    node = 0;
    st.clear();
    dfs(i);
    if (node == (int)st.size() + 1) {
      while (!Q.empty()) {
        auto [u, v] = Q.front();
        Q.pop();
        ans.emplace_back(u, v);
      }
    } else {
      dp();
    }
  }
  ranges::sort(ans);
  cout << ans.size() << '\n';
  for (auto [u, v] : ans) {
    cout << u + 1 << ' ' << v + 1 << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}