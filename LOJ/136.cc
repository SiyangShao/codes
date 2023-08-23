#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
struct heavy_light_decomposition {
  int n, m, s, tot;
  vector<int> fa, dep, siz, son, top, dfn, rnk;
  // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
  // top: top of path, dfn: dfs number, rnk: rank of dfs number
  vector<vector<int>> E;
  heavy_light_decomposition(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), E(_n) {
    tot = -1;
  }// if not loop, should start from odd point or the only out > int point
  // start dfs and modify the no condition
  void add_edge(int u, int v) { E[u].emplace_back(v), E[v].emplace_back(u); }
  int tree_build(int u) {
    siz[u] = 1;
    for (auto v : E[u]) {
      if (v == fa[u]) {
        continue;
      }
      fa[v] = u;
      dep[v] = dep[u] + 1;
      siz[u] += tree_build(v);
      if (son[u] == -1 || siz[v] > siz[son[u]]) {
        son[u] = v;
      }
    }
    return siz[u];
  }
  void tree_decomposition(int u, int tp) {
    top[u] = tp;
    dfn[u] = ++tot;
    rnk[tot] = u;
    if (son[u] != -1) {
      tree_decomposition(son[u], tp);
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u]) {
          continue;
        }
        tree_decomposition(v, v);
      }
    }
  }
  auto lca(int u, int v) {
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        u = fa[top[u]];
      } else {
        v = fa[top[v]];
      }
    }
    return dep[u] > dep[v] ? v : u;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m, k;
  cin >> n >> m;
  heavy_light_decomposition G(n * 2);
  vector<int> val(n * 2), nxt(n * 2);
  iota(nxt.begin(), nxt.end(), 0);
  vector<tuple<int, int, int>> edg(m);
  for (auto &[w, u, v] : edg) {
    cin >> u >> v >> w;
    u--, v--;
  }
  sort(edg.begin(), edg.end());
  int cur = n;
  for (auto &[w, u, v] : edg) {
    int x = u, y = v;
    while (nxt[x] != x) {
      nxt[x] = nxt[nxt[x]];
      x = nxt[x];
    }
    while (nxt[y] != y) {
      nxt[y] = nxt[nxt[y]];
      y = nxt[y];
    }
    if (x == y)
      continue;
    G.add_edge(cur, x);
    G.add_edge(cur, y);
    nxt[x] = nxt[y] = cur;
    val[cur] = w;
    // cout << cur << " " << w << " " << u << " " << v << "\n";
    cur++;
  }
  vector<int> vis(n * 2);
  for (int i = 0; i < n; ++i) {
    int u = i;
    while (u != nxt[u]) {
      nxt[u] = nxt[nxt[u]];
      u = nxt[u];
    }
    if (!vis[u]) {
      vis[u] = 1;
      G.tree_build(u);
      G.tree_decomposition(u, u);
    }
  }
  long long ans = 0;
  cin >> k;
  int A, B, C, P;
  cin >> A >> B >> C >> P;
  function<int()> rnd = [&]() { return A = (A * B + C) % P; };
  for (int i = 0; i < k; ++i) {
    int s = rnd() % n;
    int t = rnd() % n;
    auto x = G.lca(s, t);
    ans = ans + val[x];
    ans %= MOD;
    // cout << x << "\n";
  }
  cout << ans << "\n";
}