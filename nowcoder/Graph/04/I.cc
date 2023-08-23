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
constexpr ll N = 1e5;
vector<ll> pri;
bitset<N> vis;
auto init() {
  vis[0] = vis[1] = true;
  for (ll i = 2; i < N; ++i) {
    if (!vis[i]) {
      pri.emplace_back(i);
    }
    for (auto j : pri) {
      if (i * j >= N)
        break;
      vis[i * j] = true;
      if (i % j == 0)
        break;
    }
  }
}
auto is_prime(ll i) { return !vis[i]; }
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  dinic<ll> G(n + 2);
  for (ll i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      G.addEdge(n, i, 2);
      for (ll j = 0; j < n; ++j) {
        if (is_prime(a[i] + a[j])) {
          G.addEdge(i, j, 1);
        }
      }
    } else {
      G.addEdge(i, n + 1, 2);
    }
  }
  ll ans = G.solve(n, n + 1);
  if (ans != n) {
    cout << "Impossible\n";
    return;
  }
  vector<vector<ll>> E(n);
  const auto &edg = G.edg;
  for (ll i = 0; i < edg.size(); i += 2) {
    auto [u, v, w] = edg[i];
    if (w == 0 && u != n && v != n + 1) {
      E[u].emplace_back(v);
      E[v].emplace_back(u);
    }
  }
  vector<ll> vis(n, 0);
  vector<vector<ll>> output;
  vector<ll> tmp;
  function<void(ll)> dfs = [&](ll u) {
    vis[u] = 1;
    tmp.emplace_back(u);
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      dfs(v);
    }
  };
  for (ll i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(i);
      output.emplace_back(tmp);
      tmp.clear();
    }
  }
  cout << output.size() << "\n";
  for (auto &i : output) {
    cout << i.size() << " ";
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
  init();
  // cin >> _;
  while (_--) {
    solve();
  }
}