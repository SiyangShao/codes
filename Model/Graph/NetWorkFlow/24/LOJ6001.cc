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
    // cout << "AddEdge ";
    // cout << u << " " << v << " " << w << "\n";
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
constexpr ll inf = 1e16;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  dinic<long long> G(n + m + 2);
  int S = n + m, T = n + m + 1;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    ans += c;
    G.addEdge(S, i, c);
    while (getchar() == ' ') {
      scanf("%d", &c);
      G.addEdge(i, c - 1 + n, inf);
    }
  }
  for (int i = 0; i < m; ++i) {
    int c;
    scanf("%d", &c);
    G.addEdge(i + n, T, c);
  }
  ans -= G.solve(S, T);
  auto &&edg = G.edg;
  auto &&E = G.E;
  vector<int> vis(n + m + 2, 0);
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (auto id : E[u]) {
      auto [_, v, f] = edg[id];
      if (f > 0 && !vis[v]) {
        dfs(v);
      }
    }
  };
  dfs(S);
  for (int i = 0; i < n; ++i) {
    if (vis[i]) {
      cout << i + 1 << " ";
    }
  }
  cout << "\n";
  for (int i = n; i < n + m; ++i) {
    if (vis[i]) {
      cout << i - n + 1 << " ";
    }
  }
  cout << "\n";
  cout << ans << "\n";
}