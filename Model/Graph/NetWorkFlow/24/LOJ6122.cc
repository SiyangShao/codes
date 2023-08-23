#include <bits/stdc++.h>
using namespace std;
template <class Flow, class Cost> struct Primal_Dual { // based on EK
  struct edge {
    int u, v;
    Flow f;
    Cost c;
    edge(int _u, int _v, Flow _f, Cost _c) : u(_u), v(_v), f(_f), c(_c){};
  };
  int n;
  Cost inf_cost;
  Flow inf_flow;
  vector<vector<int>> E;
  vector<edge> edg;
  vector<pair<int, int>> p;
  vector<Cost> dis, h;
  vector<int> vis;
  Primal_Dual(int _n) : n(_n), E(_n), p(_n), dis(_n), h(_n), vis(_n) {
    inf_flow = numeric_limits<Flow>::max();
    inf_cost = numeric_limits<Cost>::max();
  };
  void addEdge(int u, int v, Flow f, Cost c) {
    int id = (int)edg.size();
    edg.emplace_back(u, v, f, c);
    edg.emplace_back(v, u, 0, -c);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  bool dijkstra(int s, int t) {
    using pii = pair<Cost, int>;
    priority_queue<pii, vector<pii>, greater<>> Q;
    fill(dis.begin(), dis.end(), inf_cost);
    fill(vis.begin(), vis.end(), 0);
    dis[s] = 0;
    Q.emplace(dis[s], s);
    while (!Q.empty()) {
      int u = Q.top().second;
      Q.pop();
      if (vis[u])
        continue;
      vis[u] = 1;
      for (auto id : E[u]) {
        auto [_, v, f, c] = edg[id];
        c = c + h[u] - h[v];
        if (f > 0 && dis[v] > dis[u] + c) {
          dis[v] = dis[u] + c;
          p[v].first = u;
          p[v].second = id;
          if (!vis[v]) {
            Q.emplace(dis[v], v);
          }
        }
      }
    }
    return dis[t] != inf_cost;
  }
  void spfa(int s) {
    queue<int> Q;
    fill(h.begin(), h.end(), inf_cost);
    h[s] = 0, vis[s] = 1;
    Q.emplace(s);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      vis[u] = 0;
      for (auto id : E[u]) {
        auto [_, v, f, c] = edg[id];
        if (f > 0 && h[v] > h[u] + c) {
          h[v] = h[u] + c;
          if (!vis[v]) {
            vis[v] = 1;
            Q.push(v);
          }
        }
      }
    }
  }
  pair<Flow, Cost> solve(int s, int t) {
    spfa(s);
    Flow maxf = 0;
    Cost minc = 0;
    while (dijkstra(s, t)) {
      auto minf = inf_flow;
      for (int i = 0; i < n; ++i) {
        h[i] += dis[i];
      }
      for (int i = t; i != s; i = p[i].first) {
        minf = min(minf, edg[p[i].second].f);
      }
      for (int i = t; i != s; i = p[i].first) {
        edg[p[i].second].f -= minf;
        edg[p[i].second ^ 1].f += minf;
      }
      maxf += minf;
      minc += minf * h[t];
    }
    return {maxf, minc};
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int N, V;
  cin >> N >> V;
  map<string, int> mp;
  map<int, string> revmp;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    mp[s] = i;
    revmp[i] = s;
  }
  Primal_Dual<long long, long long> G(N * 2 + 2);
  int S = N * 2, T = N * 2 + 1;
  function<int(int)> in = [&](int i) { return i * 2; };
  function<int(int)> out = [&](int i) { return i * 2 + 1; };
  G.addEdge(S, in(0), 2, 0);
  G.addEdge(in(0), out(0), 2, 0);
  G.addEdge(in(N - 1), out(N - 1), 2, -1);
  G.addEdge(out(N - 1), T, 2, 0);
  for (int i = 1; i + 1 < N; ++i) {
    G.addEdge(in(i), out(i), 1, -1);
  }
  constexpr long long inf = 1e16;
  for (int i = 0; i < V; ++i) {
    string s, t;
    cin >> s >> t;
    int u = mp[s], v = mp[t];
    if (u > v) {
      swap(u, v);
    }
    G.addEdge(out(u), in(v), inf, 0);
  }
  auto [_, ans] = G.solve(S, T);
  if (_ != 2) {
    cout << "No Solution!\n";
    return 0;
  }
  cout << -ans << "\n";
  auto &&edg = G.edg;
  auto &&e = G.E;
  vector<vector<int>> E(N);
  for (int i = 0; i < N; ++i) {
    for (auto id : e[out(i)]) {
      if (id % 2 != 0)
        continue;
      auto [v, _, f, c] = edg[id ^ 1];
      if (f != 0 && v != S && v != T) {
        E[i].emplace_back(v / 2);
        E[v / 2].emplace_back(i);
      }
    }
  }
  vector<int> vis(N);
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    cout << revmp[u] << "\n";
    for (auto v : E[u]) {
      if (!vis[v]) {
        dfs(v);
      }
    }
  };
  dfs(0);
  cout << revmp[0] << "\n";
}