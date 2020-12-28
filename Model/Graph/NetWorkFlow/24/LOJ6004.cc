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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  dinic<long long> G(n + m + 2);
  int S = n + m, T = n + m + 1;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    int u;
    cin >> u;
    sum += u;
    G.addEdge(S, i, u);
  }
  for (int i = 0; i < m; ++i) {
    int u;
    cin >> u;
    G.addEdge(i + n, T, u);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = n; j < n + m; ++j) {
      G.addEdge(i, j, 1);
    }
  }
  auto ans = G.solve(S, T);
  if (sum != ans) {
    cout << "0\n";
    return 0;
  }
  cout << "1\n";
  auto &&E = G.E;
  auto &&edg = G.edg;
  for (int i = 0; i < n; ++i) {
    for (auto id : E[i]) {
      auto [_, v, f] = edg[id];
      if (v >= n && v < n + m && f == 0) {
        cout << v - n + 1 << " ";
      }
    }
    cout << "\n";
  }
}