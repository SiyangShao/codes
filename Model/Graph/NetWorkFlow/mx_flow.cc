#include <bits/stdc++.h>
using namespace std;
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
  auto dfs(int s, int t, int u, Cap up) {
    if (u == s)
      return up;
    Cap res = 0;
    int levelU = level[u];
    for (auto &i = iter[u]; i < (int)g[u].size(); ++i) {
      edge &e = g[u][i];
      if (levelU <= level[e.to] || g[e.to][e.rev].cap == 0)
        continue;
      Cap d = dfs(e.to, min(up - res, g[e.to][e.rev].cap));
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
      bfs();
      if (level[t] == -1)
        break;
      fill(iter.begin(), iter.end(), 0);
      auto f = dfs(s, t, t, limit - ans);
      if (!f)
        break;
      ans += f;
    }
    return ans;
  }
};