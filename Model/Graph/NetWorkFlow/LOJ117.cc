#include <bits/stdc++.h>
using namespace std;
template <class Flow> struct dinic {
  struct edge {
    int u, v;
    Flow f;
    edge(int _u, int _v, Flow _f) : u(_u), v(_v), f(_f){};
  };
  vector<vector<int>> E;
  vector<edge> edg;
  vector<int> d, cur;
  int n;
  dinic(int _n) : E(_n), d(_n), cur(_n), n(_n) {}
  void addEdge(int u, int v, Flow w) {
    int id = (int)edg.size();
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  auto dfs(int u, int t, Flow flow) {
    if (u == t)
      return flow;
    Flow sum = 0;
    while (cur[u] < (int)E[u].size() && flow > 0) {
      auto id = E[u][cur[u]];
      auto [_, v, f] = edg[id];
      auto c = min(flow, f);
      if (d[u] + 1 == d[v] && c > 0) {
        auto add = dfs(v, t, c);
        sum += add, flow -= add, edg[id].f -= add, edg[id ^ 1].f += add;
      }
      cur[u]++;
    }
    if (cur[u] > 0)
      cur[u]--;
    if (!sum)
      d[u] = -1;
    return sum;
  }
  bool level(int s, int t) {
    fill(d.begin(), d.end(), -1);
    fill(cur.begin(), cur.end(), 0);
    queue<int> Q;
    Q.emplace(s);
    d[s] = 0;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (auto id : E[u]) {
        auto v = edg[id].v;
        if (d[v] == -1 && edg[id].f != 0)
          Q.emplace(v), d[v] = d[u] + 1;
      }
    }
    return d[t] != -1;
  }
  auto solve(int s, int t) {
    Flow ans = 0;
    while (level(s, t))
      ans += dfs(s, t, numeric_limits<Flow>::max());
    return ans;
  }
};
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--, t--;
  dinic<ll> G(n + 2);
  int SS = n, TT = n + 1;
  vector<ll> d(n);
  vector<ll> base(m);
  for (int i = 0; i < m; ++i) {
    int u, v, lower, upper;
    cin >> u >> v >> lower >> upper;
    u--, v--;
    G.addEdge(u, v, upper - lower);
    base[i] = lower;
    d[u] -= lower;
    d[v] += lower;
  }
  int id = (int)G.edg.size();
  ll ans = 0;
  constexpr ll inf = 1e16;
  G.addEdge(t, s, inf);
  for (int i = 0; i < n; ++i) {
    if (d[i] == 0)
      continue;
    if (d[i] > 0) {
      ans += d[i];
      G.addEdge(SS, i, d[i]);
    } else {
      G.addEdge(i, TT, -d[i]);
    }
  }
  auto check = G.solve(SS, TT);
  if (check != ans) {
    cout << "please go home to sleep\n";
    return 0;
  }
  auto bs = G.edg[id ^ 1].f;
  for (int i = id; i < (int)G.edg.size(); ++i) {
    G.edg[i].f = 0;
  }
  auto add = G.solve(t, s);
  cout << -add + bs << "\n";
}