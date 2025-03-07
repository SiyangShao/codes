#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class Flow, class Cost> struct Primal_Dual { // based on EK
  struct edge {
    int u, v;
    Flow f;
    Cost c;
    edge(int _u, int _v, Flow _f, Cost _c) : u(_u), v(_v), f(_f), c(_c) {};
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
    inf_flow = 5e8, inf_cost = 5e8;
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
          if (!vis[v])
            Q.emplace(dis[v], v);
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
          if (!vis[v])
            vis[v] = 1, Q.push(v);
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
      for (int i = 0; i < n; ++i)
        h[i] += dis[i];
      for (int i = t; i != s; i = p[i].first)
        minf = min(minf, edg[p[i].second].f);
      for (int i = t; i != s; i = p[i].first)
        edg[p[i].second].f -= minf, edg[p[i].second ^ 1].f += minf;
      maxf += minf, minc += minf * h[t];
    }
    return {maxf, minc};
  }
};
struct Tarjan_SCC {
  int n, edg_id, _t, sc_id;
  vector<vector<int>> E, scc;
  vector<pair<int, int>> edges;
  vector<int> dfn, low, in_scc;
  stack<int> st;
  vector<bool> in_st;
  Tarjan_SCC(int _n)
      : n(_n), E(_n), dfn(_n, -1), low(_n), in_scc(_n, -1), in_st(_n, false) {
    sc_id = edg_id = _t = 0;
  }
  void addEdge(int u, int v) {
    edges.emplace_back(u, v), E[u].emplace_back(edg_id++);
  }
  void dfs(int u) {
    low[u] = dfn[u] = _t++;
    st.emplace(u), in_st[u] = true;
    for (auto id : E[u]) {
      auto v = edges[id].second;
      if (dfn[v] == -1)
        dfs(v), low[u] = min(low[u], low[v]);
      else if (in_st[v])
        low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
      vector<int> _scc;
      _scc.clear();
      while (st.top() != u) {
        auto v = st.top();
        in_scc[v] = sc_id, _scc.emplace_back(v), in_st[v] = false;
        st.pop();
      }
      in_scc[u] = sc_id, _scc.emplace_back(u);
      scc.emplace_back(_scc);
      sc_id++;
      st.pop(), in_st[u] = false;
    }
  }
  void solve() {
    for (int i = 0; i < n; ++i)
      if (dfn[i] == -1)
        dfs(i);
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  Tarjan_SCC SCC(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    SCC.addEdge(u, v);
  }
  SCC.solve();
  vector<int> b(SCC.sc_id);
  set<pair<int, int>> st;
  {
    for (int i = 0; i < n; i++) {
      b[SCC.in_scc[i]] += a[i];
    }
    for (auto [u, v] : SCC.edges) {
      if (SCC.in_scc[u] == SCC.in_scc[v])
        continue;
      if (st.contains({SCC.in_scc[u], SCC.in_scc[v]}))
        continue;
      st.emplace(SCC.in_scc[u], SCC.in_scc[v]);
    }
  }
  Primal_Dual<int, int> G(SCC.sc_id * 3 + 4);
  int s = SCC.sc_id * 3, t = s + 1, ss = t + 1, tt = ss + 1;
  constexpr int inf = 5e8;
  for (int i = 0; i < SCC.sc_id; i++) {
    G.addEdge(ss, i * 3 + 1, 1, 0);
    G.addEdge(i * 3, tt, 1, 0);
    // force push
    G.addEdge(i * 3 + 1, i * 3, 1, (b[i] == 0 ? inf : 1));

    G.addEdge(i * 3, i * 3 + 1, inf, 0);
    G.addEdge(i * 3 + 1, i * 3 + 2, inf, 0);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
