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
  int n, k;
  cin >> n >> k;
  int nn = n;
  n = 1 << n;
  vector<tuple<int, int, int>> edg;
  vector<int> a(n);
  function<bool(int)> check = [&](int i) {
    int cnt = 0;
    while (i) {
      if (i & 1)
        cnt++;
      i >>= 1;
    }
    return cnt % 2 == 0;
  };
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    if (check(i))
      for (int j = 1; j < n; j <<= 1) {
        assert((i ^ j) < n);
        edg.emplace_back(-(a[i] + a[i ^ j]), i, i ^ j);
      }
  }
  int cc = min((2 * nn - 1) * (k - 1) + 1, (int)edg.size());
  nth_element(edg.begin(), edg.begin() + cc, edg.end());
  vector<int> mp(n, -1);
  int cnt = 0;
  for (int i = 0; i < cc; ++i) {
    auto [cost, u, v] = edg[i];
    if (mp[u] == -1) {
      mp[u] = cnt++;
    }
    if (mp[v] == -1) {
      mp[v] = cnt++;
    }
  }
  Primal_Dual<int, int> G(cnt + 3);
  int S = cnt, T = cnt + 1, mid = cnt + 2;
  for (int i = 0; i < cc; ++i) {
    auto [cost, u, v] = edg[i];
    G.addEdge(mp[u], mp[v], 1, cost);
  }
  for (int i = 0; i < n; ++i) {
    if (mp[i] == -1)
      continue;
    if (check(i)) {
      G.addEdge(S, mp[i], 1, 0);
    } else {
      G.addEdge(mp[i], mid, 1, 0);
    }
  }
  G.addEdge(mid, T, k, 0);
  auto [flow, cost] = G.solve(S, T);
  cout << -cost << "\n";
}