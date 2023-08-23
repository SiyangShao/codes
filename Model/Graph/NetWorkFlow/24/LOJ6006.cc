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
  int k, n;
  cin >> k >> n;
  dinic<long long> G(k + n + 2);
  int S = k + n, T = k + n + 1;
  int m = 0;
  for (int i = 0; i < k; ++i) {
    int u;
    cin >> u;
    m += u;
    G.addEdge(S, i, u);
  }
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    for (int j = 0; j < p; ++j) {
      int u;
      cin >> u;
      u--;
      G.addEdge(u, i + k, 1);
    }
    G.addEdge(i + k, T, 1);
  }
  auto ans = G.solve(S, T);
  if (ans != m) {
    cout << "No Solution!\n";
    return 0;
  }
  auto &&E = G.E;
  auto &&edg = G.edg;
  for (int i = 0; i < k; ++i) {
    cout << i + 1 << ": ";
    for (auto id : E[i]) {
      auto [_, v, f] = edg[id];
      if (v >= k && v < k + n && f == 0) {
        cout << v - k + 1 << " ";
      }
    }
    cout << "\n";
  }
}