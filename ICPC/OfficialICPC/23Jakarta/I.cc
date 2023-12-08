#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
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
struct DSU {
  vector<int> fa, siz;
  DSU(int n) : fa(n), siz(n, 1) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return;
    if (siz[u] > siz[v])
      swap(u, v);
    fa[u] = v;
    siz[v] += siz[u];
  }
  bool same(int u, int v) { return find(u) == find(v); }
};
auto solve() {
  int n;
  cin >> n;
  dinic<long long> G(n * 2 + 2);
  DSU dsu(n);
  int S = n * 2, T = n * 2 + 1;
  for (int i = 0; i < n; ++i) {
    G.addEdge(S, i, 1);
    G.addEdge(i + n, T, 1);
  }
  int sz = (int)G.edg.size();
  vector<vector<int>> E(n);
  vector<int> in(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G.addEdge(u, v + n, 1);
    E[u].emplace_back(v);
    in[v]++;
  }
  G.solve(S, T);
  for (int i = sz; i < (int)G.edg.size(); i += 2) {
    auto [v, u, f] = G.edg[i ^ 1];
    v -= n;
    if (f)
      dsu.merge(u, v);
  }
  queue<int> Q;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0)
      Q.emplace(i);
  }
  vector<vector<int>> line(n);
  vector<vector<int>> InEdg(n);
  vector<int> newIn(n);
  while (!Q.empty()) {
    auto u = Q.front();
    line[dsu.find(u)].emplace_back(u);
    Q.pop();
    for (auto v : E[u]) {
      in[v]--;
      if (in[v] == 0)
        Q.emplace(v);
      if (dsu.same(u, v))
        continue;
      InEdg[dsu.find(u)].emplace_back(dsu.find(v));
      newIn[dsu.find(v)]++;
    }
  }
  vector<pair<int, int>> realLine;
  for (int i = 0; i < n; ++i) {
    if (!line[i].empty() && newIn[i] == 0)
      Q.emplace(i);
  }
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    realLine.emplace_back(line[u].front(), line[u].back());
    for (auto v : InEdg[u]) {
      newIn[v]--;
      if (newIn[v] == 0)
        Q.emplace(v);
    }
  }
  vector<pair<int, int>> edg;
  for (int i = 1; i < (int)realLine.size(); ++i) {
    edg.emplace_back(realLine[i - 1].second, realLine[i].first);
  }
  cout << edg.size() << "\n";
  for (auto [u, v] : edg) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}