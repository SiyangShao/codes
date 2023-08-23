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
  vector<int> d;
  int n;
  dinic(int _n) : E(_n), d(_n), n(_n) {}
  void addEdge(int u, int v, Flow w) {
    int id = (int)edg.size();
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  auto dfs(int u, int t, Flow flow) {
    if (u == t)
      return flow;
    Flow sum = 0;
    for (auto id : E[u]) {
      if (edg[id].f != 0 && d[edg[id].v] == d[u] + 1) {
        auto tmp = dfs(edg[id].v, t, min(flow, edg[id].f));
        edg[id].f -= tmp, edg[id ^ 1].f += tmp, sum += tmp, flow -= tmp;
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
        auto v = edg[id].v;
        if (d[v] == 0 && edg[id].f != 0)
          Q.emplace(v), d[v] = d[u] + 1;
      }
    }
    return false;
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
  int n, m;
  cin >> n >> m;
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
  ll ans = 0;
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
  auto bs = G.solve(SS, TT);
  // cout<<bs<<" "<<ans<<"\n";
  if (bs != ans) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < m * 2; i += 2) {
    cout << base[i / 2] + G.edg[i ^ 1].f << "\n";
  }
}