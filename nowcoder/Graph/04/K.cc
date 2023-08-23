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
  ll N, F, D;
  cin >> N >> F >> D;
  dinic<ll> G(N + N + F + D + 2);
  ll S = N + N + F + D, T = N + N + F + D + 1;
  for (ll i = 0; i < F; ++i) {
    G.addEdge(S, i, 1);
  }
  for (ll i = 0; i < N; ++i) {
    G.addEdge(i + F, i + F + N, 1);
  }
  for (ll i = 0; i < D; ++i) {
    G.addEdge(i + N + N + F, T, 1);
  }
  for (ll i = 0; i < N; ++i) {
    ll f, d;
    cin >> f >> d;
    for (ll j = 0; j < f; ++j) {
      ll nxt;
      cin >> nxt;
      nxt--;
      G.addEdge(nxt, i + F, 1);
    }
    for (ll j = 0; j < d; ++j) {
      ll nxt;
      cin >> nxt;
      nxt--;
      G.addEdge(i + N + F, nxt + N + N + F, 1);
    }
  }
  ll ans = G.solve(S, T);
  cout << ans << "\n";
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