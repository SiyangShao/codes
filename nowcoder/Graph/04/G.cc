#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class Cap> struct dinic {
  struct edge {
    int from, to;
    Cap w;
    edge(int _f, int _t, Cap _w) : from(_f), to(_t), w(_w){};
  };
  vector<vector<int>> E;
  vector<edge> edg;
  vector<int> d;
  int n;
  dinic(int _n) : n(_n), E(_n), d(_n) {}
  void addEdge(int u, int v, Cap w) {
    int id = edg.size();
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  auto dfs(int u, int t, Cap flow) {
    if (u == t)
      return flow;
    Cap sum = 0;
    for (auto id : E[u]) {
      if (edg[id].w != 0 && d[edg[id].to] == d[u] + 1) {
        auto tmp = dfs(edg[id].to, t, min(flow, edg[id].w));
        edg[id].w -= tmp, edg[id ^ 1].w += tmp, sum += tmp, flow -= tmp;
      }
    }
    if (sum == 0)
      d[u] = 0;
    return sum;
  }
  bool level(int s, int t) {
    fill(d.begin(), d.end(), 0);
    queue<int> Q;
    Q.emplace(s);
    d[s] = 1;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      if (u == t)
        return true;
      for (auto id : E[u]) {
        auto v = edg[id].to;
        if (d[v] == 0 && edg[id].w != 0)
          Q.emplace(v), d[v] = d[u] + 1;
      }
    }
    return false;
  }
  auto solve(int s, int t) {
    Cap ans = 0;
    while (level(s, t))
      ans += dfs(s, t, numeric_limits<Cap>::max());
    return ans;
  }
};
auto solve() {
  ll n, m;
  cin >> n >> m;
  dinic<ll> G(n + m + 2);
  ll sum = 0;
  for (ll i = 0; i < n; ++i) {
    ll v;
    cin >> v;
    sum += v;
    G.addEdge(n + m, i, v);
  }
  for (ll i = 0; i < m; ++i) {
    ll v;
    cin >> v;
    G.addEdge(i + n, n + m + 1, v);
  }
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      G.addEdge(i, j + n, 1);
    }
  }
  ll ans = G.solve(n + m, n + m + 1);
  if (ans == sum) {
    cout << "1\n";
  } else {
    cout << "0\n";
    return;
  }
  const auto &edg = G.edg;
  vector<vector<ll>> E(n);
  for (ll i = 0; i < edg.size(); i += 2) {
    auto [u, v, w] = edg[i];
    if (w == 0 && u != n + m && v != n + m + 1) {
      E[u].emplace_back(v - n);
    }
  }
  for (auto &i : E) {
    for (auto &j : i) {
      cout << j + 1 << " ";
    }
    cout << "\n";
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