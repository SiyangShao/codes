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
constexpr ll N = 3e5;
bitset<N> vis;
auto is_prime(ll u) { return !vis[u]; }
vector<ll> pri;
auto init() {
  vis[0] = vis[1] = true;
  for (ll i = 2; i < N; ++i) {
    if (!vis[i]) {
      pri.emplace_back(i);
    }
    for (auto j : pri) {
      if (i * j >= N) {
        break;
      }
      vis[i * j] = true;
      if (i % j == 0) {
        break;
      }
    }
  }
}
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> L, R;
  bool add = false;
  for (auto &i : a) {
    cin >> i;
    if (i == 1) {
      if (!add) {
        add = true;
        L.emplace_back(i);
      }
    } else if (i % 2 == 1) {
      L.emplace_back(i);
    } else if (i % 2 == 0) {
      R.emplace_back(i);
    }
  }
  dinic<ll> G(L.size() + R.size() + 2);
  ll S = L.size() + R.size(), T = L.size() + R.size() + 1;
  for (ll i = 0; i < L.size(); ++i) {
    G.addEdge(S, i, 1);
  }
  for (ll i = 0; i < R.size(); ++i) {
    G.addEdge(i + L.size(), T, 1);
  }
  for (ll i = 0; i < L.size(); ++i) {
    for (ll j = 0; j < R.size(); ++j) {
      if (is_prime(L[i] + R[j])) {
        G.addEdge(i, j + L.size(), inf);
      }
    }
  }
  cout << L.size() + R.size() - G.solve(S, T);
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