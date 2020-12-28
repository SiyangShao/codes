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
      ans += dfs(s, t, numeric_limits<Flow>::max());
    return ans;
  }
};
struct DSU {
  int _;
  vector<int> fa;
  DSU(int n) : fa(n) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
      fa[u] = v;
    }
  }
};
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
auto solve() {
  int n, k;
  cin >> n >> k;
  int mp[n][n];
  DSU dsu(n * n);
  dinic<long long> flow(n * n + 3);
  int s = n * n, t = n * n + 1, ss = n * n + 2;
  flow.addEdge(ss, s, k);
  memset(mp, 0, sizeof(mp));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i % 2 == j % 2) {
        flow.addEdge(s, i * n + j, 4);
        for (int dk = 0; dk < 4; ++dk) {
          int x = i + dx[dk], y = j + dy[dk];
          if (x >= 0 && x < n && y >= 0 && y < n) {
            flow.addEdge(i * n + j, x * n + y, 1);
          }
        }
      } else {
        flow.addEdge(i * n + j, t, 4);
      }
    }
  }
  auto ans = flow.solve(ss, t);
  cout << ans << " ";
  if (ans == k) {
    cout << "Possible\n";
  } else {
    cout << "Impossible\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}