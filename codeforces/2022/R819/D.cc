#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> col(m, 0);
  vector<vector<pair<ll, ll>>> E(n);
  vector<pair<ll, ll>> edg(m);
  for (ll i = 0; i < m; ++i) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    edg[i] = {u, v};
    E[u].emplace_back(v, i);
    E[v].emplace_back(u, i);
  }
  vector<ll> vis(n, 0), level(n, -1);
  function<bool(ll)> bfs = [&](ll u) {
    queue<ll> Q;
    Q.emplace(u);
    level[u] = 1;
    fill(vis.begin(), vis.end(), 0);
    vis[u] = 1;
    while (!Q.empty()) {
      auto u = Q.front();
      Q.pop();
      for (auto [v, id] : E[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          col[id] = 1;
          Q.emplace(v);
          level[v] = level[u] + 1;
        }
      }
    }
    if (m < n + 2) {
      return true;
    }
    set<ll> st;
    st.clear();
    for (ll i = 0; i < m; ++i) {
      if (col[i] == 0) {
        st.emplace(edg[i].first);
        st.emplace(edg[i].second);
      }
    }
    if (st.size() != 3) {
      return true;
    }
    for (ll i = 0; i < m; ++i) {
      if (col[i] == 0) {
        auto u = edg[i].first;
        assert(level[u] != 1);
        for (auto [v, id] : E[u]) {
          if (level[v] == level[u] - 1 && st.find(v) == st.end()) {
            col[id] = 0;
            col[i] = 1;
            return true;
          }
        }
      }
    }
    return false;
  };
  bool ans = bfs(0);
  assert(ans);
  for (ll i = 0; i < m; ++i) {
    cout << col[i];
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