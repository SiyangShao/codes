#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
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
    // inf_flow = numeric_limits<Flow>::max();
    inf_flow = 1e16;
    // inf_cost = numeric_limits<Cost>::max();
    inf_cost = 1e16;
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
    // int id = (int)edg.size();
    // edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    // E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
    addEdged(u, v, w);
    addEdged(v, u, w);
  }
  void addEdged(int u, int v, Flow w) {
    int id = (int)edg.size();
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  auto dfs(int u, int t, Flow flow) {
    if (u == t)
      return flow;
    Flow sum = 0;
    while (cur[u] < (int)E[u].size()) {
      auto id = E[u][cur[u]];
      auto [_, v, f] = edg[id];
      auto c = min(flow, f);
      if (d[u] + 1 == d[v] && c > 0) {
        auto add = dfs(v, t, c);
        sum += add, flow -= add, edg[id].f -= add, edg[id ^ 1].f += add;
      }
      if (!flow)
        break;
      cur[u]++;
    }
    if (!sum)
      d[u] = -1;
    return sum;
  }
  bool level(int s, int t) {
    fill(d.begin(), d.end(), -1), fill(cur.begin(), cur.end(), 0);
    queue<int> Q;
    Q.emplace(s), d[s] = 0;
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
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector r(n, vector<ll>(m - 1)), c(n - 1, vector<ll>(m));
  for (auto &i : r)
    for (auto &j : i)
      cin >> j;
  for (auto &i : c)
    for (auto &j : i)
      cin >> j;
  dinic<ll> G((n - 1) * (m - 1) + 4);
  int S1 = (n - 1) * (m - 1), T1 = (n - 1) * (m - 1) + 1,
      S2 = (n - 1) * (m - 1) + 2, T2 = (n - 1) * (m - 1) + 3;
  // S1 = S2, T1 = T2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) {
      if (i == 0) {
        G.addEdge(S1, i * (m - 1) + j, r[i][j]);
      } else if (i + 1 == n) {
        G.addEdge((i - 1) * (m - 1) + j, T1, r[i][j]);
      } else {
        G.addEdge((i - 1) * (m - 1) + j, i * (m - 1) + j, r[i][j]);
      }
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j == 0) {
        // G.addEdge(S2, i * (m - 1) + j, c[i][j]);
      } else if (j + 1 == m) {
        // G.addEdge(i * (m - 1) + j - 1, T2, c[i][j]);
      } else {
        G.addEdge(i * (m - 1) + j - 1, i * (m - 1) + j, c[i][j]);
      }
    }
  }
  G.solve(S1, T1);
  // cout << G.solve(S2, T2) << "\n";
  Primal_Dual<ll, ll> E((n - 1) * (m - 1) + 5);
  int realS = (n - 1) * (m - 1) + 4;
  E.addEdge(realS, S1, k, 0);
  for (int i = 0; i < (int)G.edg.size(); i += 2) {
    auto [u, v, f] = G.edg[i];
    E.addEdge(u, v, inf, 1);
    auto [_u, _v, revF] = G.edg[i ^ 1];
    // cout << "DBG" << u << " " << v << " " << res << "\n";
    if (f)
      E.addEdge(u, v, f, 0);
    if (revF)
      E.addEdge(v, u, revF, 0);
  }
  auto [_f, cost] = E.solve(realS, T1);
  cout << cost << "\n";
  for (int i = 0; i < (int)E.edg.size(); i += 2) {
    auto [u, v, f, curc] = E.edg[i];
    if (curc != 1)
      continue;
    auto [_u, _v, realF, _c] = E.edg[i ^ 1];
    if (u == T1 || u == T2 || v == S1 || v == S2)
      swap(u, v);
    if (u == S1) {
      // i * (m-1) + j
      int jj = v % (m - 1);
      int ii = v / (m - 1);
      r[ii][jj] += realF;
    } else if (u == S2) {
      int jj = v % (m - 1);
      int ii = v / (m - 1);
      c[ii][jj] += realF;
    } else if (v == T1) {
      int jj = u % (m - 1);
      int ii = u / (m - 1) + 1;
      r[ii][jj] += realF;
    } else if (v == T2) {
      int jj = u % (m - 1) + 1;
      int ii = u / (m - 1);
      c[ii][jj] += realF;
    } else {
      if (u > v)
        swap(u, v);
      dbg(u, v);
      if (v == u + m - 1) {
        int jj = u % (m - 1);
        int ii = u / (m - 1) + 1;
        dbg(ii, jj);
        r[ii][jj] += realF;
      } else {
        assert(v == u + 1);
        int jj = u % (m - 1) + 1;
        int ii = u / (m - 1);
        dbg(ii, jj);
        c[ii][jj] += realF;
      }
    }
  }
  for (auto &i : r) {
    for (auto &j : i)
      cout << j << " ";
    cout << "\n";
  }
  for (auto &i : c) {
    for (auto &j : i)
      cout << j << " ";
    cout << "\n";
  }
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