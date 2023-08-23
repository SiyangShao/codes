#include <bits/stdc++.h>
using namespace std;
template <class Flow> struct hlpp {
  struct edge {
    int u, v;
    Flow f;
    edge(int _u, int _v, Flow _f) : u(_u), v(_v), f(_f){};
  };
  int n, level{};
  vector<vector<int>> E;
  vector<edge> edg;
  vector<int> h, gap;
  vector<Flow> ex;
  vector<stack<int>> B;
  hlpp(int _n) : n(_n), E(_n), h(_n), gap(_n), ex(_n), B(_n){};
  void addEdge(int u, int v, Flow w) {
    int id = (int)edg.size();
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  bool push(int u, int s, int t) {
    bool init = u == s; 
    for (auto id : E[s]) {
      auto &[_, v, f] = edg[id];
      if (!f || (!init && h[u] != h[v] + 1))
        continue;
      auto k = init ? f : min(f, ex[u]);
      if (v != s && v != t && !ex[v])
        B[h[v]].push(v), level = max(level, h[v]);
      ex[u] -= k, ex[v] += k, edg[id].f -= k, edg[id ^ 1].f += k;
      if (!ex[u])
        return false;
    }
    return true;
  }
  void relabel(int u) {
    h[u] = 3 * n;
    for (auto id : E[u]) {
      auto [_, v, f] = edg[id];
      if (f)
        h[u] = min(h[u], h[v]);
    }
    if (++h[u] < n) {
      B[h[u]].emplace(u);
      level = max(level, h[u]);
      gap[h[u]]++;
    }
  }
  bool bfs(int s, int t) {
    fill(h.begin(), h.end(), n * 3);
    queue<int> q;
    q.emplace(t), h[t] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto id : E[u]) {
        auto [_, v, f] = edg[id];
        if (edg[id ^ 1].f && h[v] > h[u] + 1) {
          h[v] = h[u] + 1;
          q.emplace(v);
        }
      }
    }
    return h[s] != n * 3;
  }
  int top() {
    while (B[level].empty() && level >= 0)
      level--;
    return level == -1 ? -1 : B[level].top();
  }
  auto solve(int s, int t) {
		level = 0;
    if (!bfs(s, t))
      return Flow(0);
    fill(gap.begin(), gap.end(), 0);
    for (int i = 0; i < n; ++i) {
      if (h[i] != n*3) {
        gap[h[i]]++;
      }
    }
    h[s] = n;
    push(s,s,t);
    while (true) {
      int u = top();
      if (u == -1)
        break;
      B[level].pop();
      if (push(u, s, t)) {
        if (!--gap[h[u]]) {
          for (int i = 0; i < n; ++i) {
            if (i != s && i != t && h[i] > h[u] && h[i] < n + 1) {
              h[i] = n + 1;
            }
          }
        }
        relabel(u);
      }
    }
    return ex[t];
  }
};

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  hlpp<long long> G(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    G.addEdge(u, v, w);
  }
  s--, t--;
  cout << G.solve(s, t) << "\n";
}