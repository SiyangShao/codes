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
  vector<int> d, q;
  int n;
  dinic(int _n) : n(_n), E(_n), d(_n), q(_n) {}
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
    int l = 0, r = 0;
    d[s] = 1, q[r++] = s;
    while (l < r) {
      int u = q[l++];
      if (u == t)
        return true;
      for (auto id : E[u]) {
        auto v = edg[id].to;
        if (d[v] == 0 && edg[id].w != 0)
          q[r++] = v, d[v] = d[u] + 1;
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
  dinic<ll> E(n + m + 2);
  for (ll i = 1; i <= n; ++i) {
    ll k;
    cin >> k;
    E.addEdge(0, i, 1);
    for (ll j = 1; j <= k; ++j) {
      ll tmp;
      cin >> tmp;
      E.addEdge(i, tmp + n, 1);
    }
  }
  for (ll j = 1; j <= m; ++j) {
    E.addEdge(j + n, n + m + 1, 1);
  }
  cout << m - E.solve(0, n + m + 1);
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