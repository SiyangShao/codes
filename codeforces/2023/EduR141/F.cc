#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    while (cur[u] < (int)E[u].size() && flow > 0) {
      auto id = E[u][cur[u]];
      auto [_, v, f] = edg[id];
      auto c = min(flow, f);
      if (d[u] + 1 == d[v] && c > 0) {
        auto add = dfs(v, t, c);
        sum += add, flow -= add, edg[id].f -= add, edg[id ^ 1].f += add;
      }
      cur[u]++;
    }
    if (cur[u] > 0)
      cur[u]--;
    if (!sum)
      d[u] = -1;
    return sum;
  }
  bool level(int s, int t) {
    fill(d.begin(), d.end(), -1);
    fill(cur.begin(), cur.end(), 0);
    queue<int> Q;
    Q.emplace(s);
    d[s] = 0;
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
  int n;
  vector<int> fa, siz;
  DSU(int _) : n(_), fa(_), siz(_, 1) { iota(fa.begin(), fa.end(), 0); }
  int find(int x) {
    if (x != fa[x]) {
      fa[x] = find(fa[x]);
    }
    return fa[x];
  }
  int merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return 0;
    if (x > y) {
      swap(x, y);
    }
    siz[x] += siz[y];
    fa[y] = x;
    return 1;
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  DSU l(n), r(n);
  dinic<ll> G(n * 4 + 2);
  int S = n * 2, T = n * 2 + 1, cur = n * 2 + 2;
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  for (auto &i : b) {
    cin >> i;
    i--;
  }
  for (int i = 0; i < n; ++i) {
    l.merge(i, a[i]);
    r.merge(i, b[i]);
  }
  vector<int> mpl(n, -1), mpr(n, -1);
  ll base = 0;
  for (int i = 0; i < n; ++i) {
    if (l.find(i) == i) {
      mpl[i] = cur++;
      base += l.siz[i] - 1;
      G.addEdge(S, mpl[i], l.siz[i] - 1);
    }
    if (r.find(i) == i) {
      mpr[i] = cur++;
      base += r.siz[i] - 1;
      G.addEdge(mpr[i], T, r.siz[i] - 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    auto fa_l = l.find(i);
    G.addEdge(mpl[fa_l], i, 1);
    auto fa_r = r.find(i);
    G.addEdge(i + n, mpr[fa_r], 1);
  }
  int cur_size = (int)G.edg.size();
  for (int i = 0; i < n; ++i) {
    G.addEdge(i, i + n, 1);
  }
  auto ans = G.solve(S, T);
  cout << base - ans << "\n";
  vector<int> vis(n, 0);
  for (int i = cur_size; i < (int)G.edg.size(); i += 2) {
    if (G.edg[i ^ 1].f == 1) {
      int x = G.edg[i].u;
      cout << x + 1 << " ";
      vis[x] = 1;
      l.siz[l.find(x)]--;
      r.siz[r.find(x)]--;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (vis[i])
      continue;
    if (l.siz[l.find(i)] > 1) {
      l.siz[l.find(i)]--;
      cout << i + 1 << " ";
      vis[i]++;
    }
    if (r.siz[r.find(i)] > 1) {
      r.siz[r.find(i)]--;
      cout << i + 1 << " ";
      vis[i]++;
    }
    assert(vis[i] != 2);
  }
  cout << "\n";
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
