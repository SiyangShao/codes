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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }
  vector<tuple<int, int, int, int>> lines(m);
  vector<tuple<int, int, int>> edg;
  const int S = 0;
  int t = n + m;
  for (auto &[a, b, x, y] : lines) {
    cin >> a >> b >> x >> y;
    a--, b--;
  }
  long long pre_sum = 0;
  for (int i = 0; i < m; ++i) {
    auto &[a, b, x, y] = lines[i];
    x -= y;
    if (x >= 0) {
      pre_sum += x;
    } else {
      x = 0;
    }
    edg.emplace_back(S, i + n, x);
  }

  vector<int> pa(n, -1);
  vector<int> fa(n), to(n), pw(n);
  iota(fa.begin(), fa.end(), 0);
  auto find = [&](auto self, int x) -> int {
    if (fa[fa[x]] == fa[x])
      return fa[x];
    self(self, fa[x]);
    int e = t++;
    if (to[fa[x]]) {
      edg.emplace_back(e, to[fa[x]], -1);
    }
    edg.emplace_back(e, to[x], -1);
    to[x] = e;
    fa[x] = fa[fa[x]];
    return fa[x];
  };
  vector<vector<int>> vec(n);
  for (int i = 0; i < m; ++i) {
    const auto &[a, b, x, y] = lines[i];
    vec[a].emplace_back(i);
    vec[b].emplace_back(i);
  }
  vector<bool> vis(m);
  auto dfs = [&](auto self, int u) -> void {
    for (auto [v, w] : E[u]) {
      if (v == pa[u])
        continue;
      pw[v] = w;
      pa[v] = u;
      self(self, v);
      fa[v] = u;
      to[v] = v;
    }
    for (auto i : vec[u]) {
      auto &[a, b, x, y] = lines[i];
      if (!vis[i]) {
        vis[i] = true;
        if (u == b) {
          swap(a, b);
        }
      } else if (u == b) {
        int nxt = find(find, a);
        edg.emplace_back(n + i, to[a], -1);
        if (nxt != u) {
          vec[nxt].emplace_back(i);
        }
      } else {
        find(find, b);
        edg.emplace_back(n + i, to[b], -1);
      }
    }
  };
  dfs(dfs, 0);
  for (int i = 1; i < n; ++i) {
    edg.emplace_back(i, t, pw[i]);
  }
  dinic<long long> G(t + 1);
  for (auto [u, v, w] : edg) {
    cout << u << " " << v << " " << w << endl;
    G.addEdge(u, v, w == -1 ? (long long)1e16 : (long long)w);
  }
  auto ans = G.solve(S, t);
  cout << pre_sum - ans << '\n';
}