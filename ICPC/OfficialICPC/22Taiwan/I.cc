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
constexpr int N = 2010;
array<int, N * N> mp;
auto solve() {
  int m, n;
  cin >> m >> n;
  dinic<long long> G(n + m + 2);
  int S = n + m, T = n + m + 1;
  for (int i = 0; i < m; ++i) {
    G.addEdge(S, i, 1);
  }
  for (int i = m; i < m + n; ++i) {
    G.addEdge(i, T, 1);
  }
  vector<tuple<int, int, int, int>> up(m), lo(n);
  for (auto &[x1, y1, x2, y2] : up) {
    cin >> x1 >> y1 >> x2 >> y2;
  }
  fill(mp.begin(), mp.end(), -1);
  {
    int cnt = 0;
    for (auto &[x1, y1, x2, y2] : lo) {
      cin >> x1 >> y1 >> x2 >> y2;
      mp[x1 * N + y1] = cnt++;
    }
  }
  auto check = [&](tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
    auto [x11, y11, x12, y12] = a;
    auto [x21, y21, x22, y22] = b;
    int x1 = max(x11, x21), y1 = max(y11, y21);
    int x2 = min(x12, x22), y2 = min(y12, y22);
    if (x1 >= x2 || y1 >= y2) {
      return false;
    }
    int size = (x2 - x1) * (y2 - y1);
    int presize = (x12 - x11) * (y12 - y11);
    return size * 2 >= presize;
  };
  for (int i = 0; i < m; ++i) {
    auto [x1, y1, x2, y2] = up[i];
    for (int dx = -4; dx <= x2 - x1; ++dx) {
      for (int dy = -4; dy <= y2 - y1; ++dy) {
        int nx = x1 + dx, ny = y1 + dy;
        if(nx < 0 || ny < 0) continue;
        // cout<<nx*N+ny<<"\n";
        auto it = mp[nx * N + ny];
        if (it == -1){
          continue;
        } else if (check(up[i], lo[it])) {
          G.addEdge(i, m + it, 1);
        }
      }
    }
  }
  // for (int i = 0; i < m; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     if (check(up[i], lo[j])) {
  //       // cout<<i<<" "<<j<<"\n";
  //       G.addEdge(i, j + m, 1);
  //     }
  //   }
  // }
  cout << G.solve(S, T) << "\n";
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