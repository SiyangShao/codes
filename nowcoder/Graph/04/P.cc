#include <bits/stdc++.h>
using namespace std;
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
        if (sum == flow)
          return sum;
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
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  ll n, m;
  cin >> n >> m;
  ll ans = 0;
  vector mp(n, vector<ll>(m));
  for (auto &i : mp) {
    for (auto &j : i) {
      cin >> j;
      ans += j;
    }
  }
  function<ll(ll, ll)> cal = [&](ll x, ll y) { return x * m + y; };
  dinic<ll> G(n * m + 2);
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      if ((i + j) % 2 == 0) {
        G.addEdge(n * m, cal(i, j), mp[i][j]);
        for (auto [dx, dy] :
             vector<pair<ll, ll>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
          ll x = i + dx, y = j + dy;
          if (x >= 0 && x < n && y >= 0 && y < m) {
            G.addEdge(cal(i, j), cal(x, y), inf);
          }
        }
      } else
        G.addEdge(cal(i, j), n * m + 1, mp[i][j]);
    }
  }
  cout << ans - G.solve(n * m, n * m + 1);
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