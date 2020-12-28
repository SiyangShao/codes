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
  void addEdge(int u, int v, Flow w, Flow revw) {
    int id = (int)edg.size();
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, revw);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
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
constexpr long long inf = 1e16;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  dinic<long long> G(n + 4);
  int S = 0, T = n + 1, SS = n + 2, TT = n + 3;
  vector<int> m(n + 2);
  for (int i = 1; i <= n; ++i) {
    G.addEdge(S, i, inf);
    G.addEdge(i, T, inf);
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int u;
      cin >> u;
      G.addEdge(i, u, inf - 1);
      m[i]--;
      m[u]++;
    }
  }
  int beg = (int)G.edg.size();
  G.addEdge(T, S, inf);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (m[i] == 0)
      continue;
    if (m[i] > 0) {
      sum += m[i];
      G.addEdge(SS, i, m[i]);
    } else {
      G.addEdge(i, TT, -m[i]);
    }
  }

  long long ans = G.solve(SS, TT);
  assert(ans == sum);
  auto base = G.edg[beg ^ 1].f;
  for (int i = beg; i < (int)G.edg.size(); ++i) {
    G.edg[i].f = 0;
  }
  auto mx = G.solve(T, S);
  cout << base - mx << "\n";
}