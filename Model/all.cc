#include <bits/stdc++.h>
using namespace std;
struct heavy_light_decomposition {
  int n, m, s, tot;
  vector<int> fa, dep, siz, son, top, dfn, rnk;
  // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
  // top: top of path, dfn: dfs number, rnk: rank of dfs number
  vector<vector<int>> E;
  heavy_light_decomposition(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), E(_n) {
    tot = -1;
  }
  void add_edge(int u, int v) { E[u].emplace_back(v), E[v].emplace_back(u); }
  int tree_build(int u) {
    siz[u] = 1;
    for (auto v : E[u]) {
      if (v == fa[u]) {
        continue;
      }
      fa[v] = u;
      dep[v] = dep[u] + 1;
      siz[u] += tree_build(v);
      if (son[u] == -1 || siz[v] > siz[son[u]]) {
        son[u] = v;
      }
    }
    return siz[u];
  }
  void tree_decomposition(int u, int tp) {
    top[u] = tp;
    dfn[u] = ++tot;
    rnk[tot] = u;
    if (son[u] != -1) {
      tree_decomposition(son[u], tp);
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u]) {
          continue;
        }
        tree_decomposition(v, v);
      }
    }
  }
  auto lca(int u, int v) {
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        u = fa[top[u]];
      } else {
        v = fa[top[v]];
      }
      if (u == -1 || v == -1) {
        return u;
      }
    }
    return dep[u] > dep[v] ? v : u;
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
template <class Flow, class Cost>
struct Primal_Dual { // based on EK. 5e3 and 5e4 on random graph
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
struct Tarjan_BCC {
  int n, _t, edg_id;
  vector<vector<int>> E, child;
  vector<pair<int, int>> edges;
  vector<int> dfn, low, fa;
  vector<bool> cut;
  Tarjan_BCC(int _n)
      : n(_n), E(n), child(n), dfn(n, -1), low(n), fa(n, -1), cut(n, false) {
    edg_id = _t = 0;
  }
  void addEdge(int u, int v) {
    edges.emplace_back(u, v), E[u].emplace_back(edg_id),
        E[v].emplace_back(edg_id);
    edg_id++;
  }
  void dfs(int u, int fa_id) {
    low[u] = dfn[u] = _t++;
    for (auto id : E[u]) {
      auto v = edges[id].first ^ edges[id].second ^ u;
      if (id == fa_id)
        continue;
      if (dfn[v] != -1) {
        low[u] = min(low[u], dfn[v]);
      } else {
        fa[v] = u;
        dfs(v, id);
        child[u].emplace_back(v), low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u])
          cut[u] = true;
      }
    }
    if (fa_id == -1)
      cut[u] = child[u].size() > 1;
  }
  void solve() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1)
        dfs(i, -1);
    }
  }
  bool is_cut(int u) { return cut[u]; }
  vector<vector<int>> BCC_point() {
    vector<vector<int>> BCC;
    vector<int> tmp;
    vector<bool> vis(n, false);
    stack<int> st;
    function<void(int)> dfs = [&](int u) {
      st.emplace(u), vis[u] = true;
      for (auto v : child[u]) {
        dfs(v);
        if (low[v] >= dfn[u]) {
          tmp.clear();
          while (!st.empty() && st.top() != v) {
            tmp.emplace_back(st.top());
            st.pop();
          }
          tmp.emplace_back(st.top());
          st.pop(), tmp.emplace_back(u);
          BCC.emplace_back(tmp);
        }
      }
    };
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        if (child[i].empty())
          BCC.emplace_back(vector{i});
        dfs(i);
      }
    }
    return BCC;
  }
  bool is_bridge(int id) {
    return is_bridge(edges[id].first, edges[id].second);
  }
  bool is_bridge(int u, int v) { // assert there's an edge u-v
    if (dfn[u] > dfn[v])
      swap(u, v);
    return low[v] > dfn[u];
  }
  vector<vector<int>> BCC_edge() {
    vector<vector<int>> BCC;
    vector<int> tmp;
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int u) {
      vis[u] = true, tmp.emplace_back(u);
      for (auto v : child[u])
        if (!is_bridge(u, v))
          dfs(v);
    };
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        tmp.clear();
        dfs(i);
        BCC.emplace_back(tmp);
      }
    }
    return BCC;
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
    edges.emplace_back(u, v), E[u].emplace_back(edg_id);
    // E[v].emplace_back(edg_id);
    edg_id++;
  }
  void dfs(int u) {
    low[u] = dfn[u] = _t++;
    st.emplace(u), in_st[u] = true;
    for (auto id : E[u]) {
      auto v = edges[id].second;
      if (dfn[v] == -1) {
        dfs(v);
        low[u] = min(low[u], low[v]);
      } else if (in_st[v]) {
        low[u] = min(low[u], dfn[v]);
      }
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
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1) {
        dfs(i);
      }
    }
  }
};
template <class length> struct Difference_Constraints {
  int n;
  vector<vector<pair<int, length>>> E;
  vector<length> dis;
  vector<int> cnt, vis;
  Difference_Constraints(int _n)
      : n(_n), E(_n + 1), dis(_n + 1, numeric_limits<length>::max()),
        cnt(_n + 1), vis(_n + 1){};
  void add_condition(int u, int v, length y) {
    // xu - xv <= y
    E[v].emplace_back(u, y);
  }
  auto spfa(int s = 0) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      vis[u] = 0;
      for (auto [v, w] : E[u]) {
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          cnt[v] = cnt[v] + 1;
          if (cnt[v] > n) {
            return false;
          }
          if (!vis[v]) {
            q.push(v);
            vis[v] = 1;
          }
        }
      }
    }
    return true;
  }
  auto solve() {
    for (int i = 1; i <= n; ++i) {
      E[0].emplace_back(i, 0);
    }
    if (spfa()) {
      // cout<<"YES\n";
      for (int i = 1; i <= n; ++i) {
        cout << dis[i] << " ";
      }
    } else {
      cout << "NO\n";
    }
  }
};
struct MaximumMatching { // nm
  int n, m;
  vector<vector<int>> E;
  vector<int> vis, link;
  MaximumMatching(int _n, int _m) : n(_n), m(_m), E(_n), vis(_m), link(_m){};
  bool dfs(int u) {
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      vis[v] = 1;
      if (link[v] == -1 || dfs(link[v])) {
        link[v] = u;
        return true;
      }
    }
    return false;
  };
  void solve() {
    fill(link.begin(), link.end(), -1);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      // dfs(i) x times means add x points same as point i in the map
      if (dfs(i)) {
        fill(vis.begin(), vis.end(), 0);
        cnt++;
      }
    }
  }
};
template <class Cap> struct Hungarain {
  // O(n^3), only wokrs on *bipartite graph maximum perfect matching*
  // ok if negative
  int n;
  vector<int> match_x, match_y, pre;
  vector<bool> vis_x, vis_y;
  vector<vector<Cap>> g;
  vector<Cap> slack;
  vector<Cap> lx, ly;
  Cap inf, res;
  queue<int> q;
  int org_n, org_m;
  Hungarain(int _n, int _m) {
    org_n = _n, org_m = _m;
    n = max(_n, _m);
    inf = numeric_limits<Cap>::max();
    res = 0;
    // if negative, change here to -inf
    g = vector<vector<Cap>>(n, vector<Cap>(n));
    match_x = match_y = vector<int>(n, -1);
    pre = vector<int>(n);
    vis_x = vis_y = vector<bool>(n);
    lx = vector<Cap>(n, -inf);
    ly = vector<Cap>(n);
    slack = vector<Cap>(n);
  };
  void addEdge(int u, int v, Cap w) { g[u][v] = w; }
  bool check(int v) {
    vis_y[v] = true;
    if (match_y[v] != -1) {
      q.push(match_y[v]);
      vis_x[match_y[v]] = true;
      return false;
    }
    while (v != -1) {
      match_y[v] = pre[v];
      swap(v, match_x[pre[v]]);
    }
    return true;
  }
  void bfs(int i) {
    while (!q.empty()) {
      q.pop();
    }
    q.push(i);
    vis_x[i] = true;
    while (true) {
      while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v) {
          if (!vis_y[v]) {
            auto delta = lx[u] + ly[v] - g[u][v];
            if (slack[v] >= delta) {
              pre[v] = u;
              if (delta) {
                slack[v] = delta;
              } else if (check(v)) {
                return;
              }
            }
          }
        }
      }
      auto a = inf;
      for (int j = 0; j < n; ++j) {
        if (!vis_y[j]) {
          a = min(a, slack[j]);
        }
      }
      for (int j = 0; j < n; ++j) {
        if (vis_x[j]) {
          lx[j] -= a;
        }
        if (vis_y[j]) {
          ly[j] += a;
        } else {
          slack[j] -= a;
        }
      }
      for (int j = 0; j < n; ++j) {
        if (!vis_y[j] && slack[j] == 0 && check(j)) {
          return;
        }
      }
    }
  }
  void solve() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        lx[i] = max(lx[i], g[i][j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      fill(slack.begin(), slack.end(), inf);
      fill(vis_x.begin(), vis_x.end(), false);
      fill(vis_y.begin(), vis_y.end(), false);
      bfs(i);
    }
    // output
    for (int i = 0; i < n; ++i) {
      if (g[i][match_x[i]] > 0) {
        // have edge, if negative change >0 to >-inf
        res += g[i][match_x[i]];
      } else {
        // no match
        match_x[i] = -1;
      }
    }
  }
};
struct blossom { // n^3
  int n, vis_t;
  vector<vector<int>> E;
  vector<int> match, label, org, vis, parent;
  queue<int> Q;
  blossom(int _n)
      : n(_n), E(_n), match(_n, -1), label(_n), org(_n), vis(_n),
        parent(_n, -1) {
    iota(org.begin(), org.end(), 0);
    vis_t = 0;
  }
  void addEdge(int u, int v) {
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  auto lca(int v, int u) {
    vis_t++;
    while (true) {
      if (v != -1) {
        if (vis[v] == vis_t) {
          return v;
        }
        vis[v] = vis_t;
        if (match[v] == -1) {
          v = -1;
        } else {
          v = org[parent[match[v]]];
        }
      }
      swap(v, u);
    }
  }
  void agument(int v) {
    while (v != -1) {
      auto pv = parent[v];
      auto nxt = match[pv];
      match[v] = pv;
      match[pv] = v;
      v = nxt;
    }
  }
  void flower(int v, int u, int a) {
    while (org[v] != a) {
      parent[v] = u;
      u = match[v];
      if (label[u] == 1) {
        label[u] = 0;
        Q.emplace(u);
      }
      org[v] = org[u] = a;
      v = parent[u];
    }
  }
  auto bfs(int root) {
    fill(label.begin(), label.end(), -1);
    iota(org.begin(), org.end(), 0);
    while (!Q.empty()) {
      Q.pop();
    }
    Q.emplace(root);
    label[root] = 0;
    while (!Q.empty()) {
      auto u = Q.front();
      Q.pop();
      for (auto v : E[u]) {
        if (label[v] == -1) {
          label[v] = 1;
          parent[v] = u;
          if (match[v] == -1) {
            agument(v);
            return true;
          }
          label[match[v]] = 0;
          Q.push(match[v]);
          continue;
        } else if (label[v] == 0 && org[v] != org[u]) {
          auto a = lca(org[u], org[v]);
          flower(v, u, a);
          flower(u, v, a);
        }
      }
    }
    return false;
  }
  void solve() {
    for (int i = 0; i < n; ++i) {
      if (match[i] == -1) {
        bfs(i);
      }
    }
  }
};