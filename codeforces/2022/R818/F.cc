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
  vector<ll> s(n), a(n), deg(n);
  for (auto &i : s) {
    cin >> i;
  }
  for (auto &i : a) {
    cin >> i;
  }
  vector<pair<ll, ll>> op(m);
  for (auto &[u, v] : op) {
    cin >> u >> v;
    u--, v--;
    deg[u]++, deg[v]++;
  }
  dinic<ll> G(n + m + 2 + 2);
  ll _s = n + m, _t = _s + 1, __s = _t + 1, __t = __s + 1;
  ll expect = 0;
  for (ll i = 0; i < n; ++i) {
    if (s[i] != 0) {
      if ((deg[i] + a[i]) % 2 != 0) {
        cout << "NO\n";
        return;
      }
      auto out = (deg[i] + a[i]) / 2;
      if (out < 0) {
        cout << "NO\n";
        return;
      }
      expect += out;
      G.addEdge(i, __t, out);
      G.addEdge(__s, _t, out);
    } else {
      G.addEdge(i, _t, deg[i]);
    }
  }
  vector<ll> label(m);
  for (ll i = 0; i < m; ++i) {
    auto [x, y] = op[i];
    expect++;
    G.addEdge(_s, __t, 1);
    G.addEdge(__s, n + i, 1);
    G.addEdge(n + i, x, 1);
    label[i] = G.edg.size();
    G.addEdge(n + i, y, 1);
  }
  G.addEdge(_t, _s, numeric_limits<ll>::max());
  auto flow = G.solve(__s, __t);
  if (flow != expect) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (ll i = 0; i < m; ++i) {
    auto [x, y] = op[i];
    if (G.edg[label[i]].w == 0) {
      cout << x + 1 << " " << y + 1 << "\n";
    } else {
      cout << y + 1 << " " << x + 1 << "\n";
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