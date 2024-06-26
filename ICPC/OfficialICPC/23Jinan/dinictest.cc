#include <bits/stdc++.h>
using namespace std;
template <class Flow> struct dinic {
  static constexpr Flow inf = 1e16;
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
      ans += dfs(s, t, inf);
    return ans;
  }
};
template <class Cap> struct mf_graph {
  using pii = pair<int, int>;
  int n;
  struct edge {
    int to, rev;
    Cap cap;
    edge(int _to, int _rev, Cap _cap) : to(_to), rev(_rev), cap(_cap) {}
  };
  vector<pii> pos;
  vector<vector<edge>> g;
  vector<int> level, iter;
  queue<int> que;
  mf_graph() : n(0) {}
  explicit mf_graph(int _n) : n(_n), g(_n), level(_n), iter(_n){};
  int addEdge(int from, int to, Cap cap) {
    int m = (int)pos.size();
    int fromId = (int)g[from].size(), toId = (int)g[to].size();
    pos.emplace_back(from, fromId);
    if (from == to)
      toId++;
    g[from].emplace_back(to, toId, cap);
    g[to].emplace_back(from, fromId, 0);
    return m;
  }
  auto bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    level[s] = 0, que = queue(deque<int>{s});
    while (!que.empty()) {
      auto u = que.front();
      que.pop();
      for (auto e : g[u]) {
        if (e.cap == 0 || level[e.to] >= 0)
          continue;
        level[e.to] = level[u] + 1;
        if (e.to == t)
          return;
        que.emplace(e.to);
      }
    }
  }
  auto dfs(int s, int u, Cap up) {
    if (u == s)
      return up;
    Cap res = 0;
    int levelU = level[u];
    for (auto &i = iter[u]; i < (int)g[u].size(); ++i) {
      edge &e = g[u][i];
      if (levelU <= level[e.to] || g[e.to][e.rev].cap == 0)
        continue;
      Cap d = dfs(s, e.to, min(up - res, g[e.to][e.rev].cap));
      if (d <= 0)
        continue;
      g[u][i].cap += d, g[e.to][e.rev].cap -= d;
      res += d;
      if (res == up)
        return res;
    }
    level[u] = n;
    return res;
  }
  Cap flow(int s, int t, Cap limit = 1e16) {
    Cap ans = 0;
    while (ans < limit) {
      bfs(s, t);
      if (level[t] == -1)
        break;
      fill(iter.begin(), iter.end(), 0);
      auto f = dfs(s, t, limit - ans);
      if (!f)
        break;
      ans += f;
    }
    return ans;
  }
};

auto solve() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  dinic<long long> G(n);
  for (int i = 0; i < m; ++i) {
    int u, v, f;
    cin >> u >> v >> f;
    u--, v--;
    G.addEdge(u, v, f);
  }
  cout << G.solve(s - 1, t - 1) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin>>_;
  while (_--) {
    solve();
  }
}