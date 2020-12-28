#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class Cap, class Cost> struct dinic {
  struct edge {
    int from, to;
    Cap w;
    Cost c;
    edge(int _f, int _t, Cap _w, Cost _c) : from(_f), to(_t), w(_w), c(_c){};
  };
  vector<vector<int>> E;
  vector<edge> edg;
  vector<Cap> d;
  vector<bool> vis;
  int n;
  Cost ret, inf;
  dinic(int _n)
      : n(_n), E(_n), d(_n), vis(_n), ret(0), inf(numeric_limits<Cost>::max()) {
  }
  void addEdge(int u, int v, Cap w, Cost c) {
    int id = edg.size();
    edg.emplace_back(u, v, w, c), edg.emplace_back(v, u, 0, -c);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  auto dfs(int u, int t, Cap flow) {
    if (u == t)
      return flow;
    vis[u] = true;
    Cap sum = 0;
    for (auto id : E[u]) {
      auto [f, to, w, c] = edg[id];
      if (!vis[to] && w != 0 && d[to] == d[u] + c) {
        auto tmp = dfs(to, t, min(flow, w));
        if (tmp)
          edg[id].w -= tmp, edg[id ^ 1].w += tmp, sum += tmp, flow -= tmp,
              ret += tmp * c;
      }
    }
    if (sum == 0)
      d[u] = 0;
    vis[u] = false;
    return sum;
  }
  bool level(int s, int t) {
    fill(d.begin(), d.end(), numeric_limits<Cost>::max());
    fill(vis.begin(), vis.end(), false);
    queue<int> q;
    q.push(s);
    d[s] = 0, vis[s] = true;
    while (!q.empty()) {
      auto u = q.front();
      q.pop(), vis[u] = false;
      for (auto id : E[u]) {
        auto v = edg[id].to;
        if (edg[id].w && d[v] > d[u] + edg[id].c) {
          d[v] = d[u] + edg[id].c;
          if (!vis[v])
            q.push(v), vis[v] = true;
        }
      }
    }
    return d[t] != inf;
  }
  pair<Cap, Cost> solve(int s, int t) {
    Cap ans = 0;
    int d = 0;
    while (level(s, t))
      ans += dfs(s, t, inf);
    return {ans, ret};
  }
};
auto solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  string a, b;
  cin >> a >> b;
  if (x >= y) {
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        ans++;
      }
    }
    if (ans % 2 == 1) {
      cout << "-1\n";
      return;
    }
    if (ans == 2) {
      bool flag = false;
      for (ll i = 0; i + 1 < n; ++i) {
        if (a[i] != b[i] && a[i + 1] != b[i + 1]) {
          flag = true;
          break;
        }
      }
      if (flag) {
        cout << min(x, y * 2) << "\n";
        return;
      }
    }
    cout << ans * y / 2 << "\n";
    return;
  }
  // x < y
  // x * (posA - posB) || y
  vector<ll> pos;
  for (ll i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      pos.emplace_back(i);
    }
  }
  if (pos.size() % 2 == 1) {
    cout << "-1\n";
    return;
  }
  n = pos.size();
  dinic<ll, ll> G(n * 2 + 3);
  for (ll i = 0; i < n; ++i) {
    G.addEdge(n * 2, i, 1, 0);
    G.addEdge(i + n, n * 2 + 1, 1, 0);
    G.addEdge(i, n * 2 + 2, 1, y);
    if (i > 0) {
      G.addEdge(i, i - 1 + n, 1, (pos[i] - pos[i - 1]) * x);
    }
    if (i + 1 < n) {
      G.addEdge(i, i + 1 + n, 1, (pos[i + 1] - pos[i]) * x);
    }
  }
  G.addEdge(n * 2 + 2, n * 2 + 1, n, 0);
  auto ans = G.solve(n * 2, n * 2 + 1);
  cout << ans.second / 2 << "\n";
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