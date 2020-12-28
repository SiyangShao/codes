#include <bits/stdc++.h>
using namespace std;
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
  }
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
using ll = long long;
auto solve() {
  int n, m, q;
  cin >> n >> m >> q;
  heavy_light_decomposition G(n);
  vector<int> red(n);
  for (int i = 0; i < m; ++i) {
    int j;
    cin >> j;
    red[j - 1] = 1;
  }
  vector<vector<pair<int, ll>>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
    G.add_edge(u, v);
  }
  G.tree_build(0);
  G.tree_decomposition(0, 0);
  vector<ll> dp(n), in_tree(n);
  function<void(int, int, ll)> dfs = [&](int u, int fa, ll w) {
    if (red[u]) {
      in_tree[u] = u;
      dp[u] = 0;
    } else {
      in_tree[u] = in_tree[fa];
      dp[u] = dp[fa] + w;
    }
    for (auto [v, _] : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u, _);
    }
  };
  dfs(0, 0, 0);
  vector<int> v;
  function<bool(ll)> check = [&](ll x) {
    int node = -1;
    ll mx_del = 0;
    for (auto i : v) {
      if (dp[i] > x) {
        mx_del = max(mx_del, dp[i] - x);
        if (node == -1) {
          node = i;
        } else if (in_tree[node] != in_tree[i]) {
          return false;
        } else {
          node = G.lca(i, node);
        }
      }
    }
    if (node == -1)
      return true;
    return dp[node] >= mx_del;
  };
  ll mx = *ranges::max_element(dp);
  while (q--) {
    int k;
    cin >> k;
    v = vector<int>(k);
    for (auto &i : v) {
      cin >> i;
      i--;
    }
    ll l = 0, r = mx;
    ll ans = r;
    while (l <= r) {
      ll mid = (l + r) / 2;
      if (check(mid)) {
        r = mid - 1;
        ans = min(ans, mid);
      } else {
        l = mid + 1;
      }
    }
    cout << ans << "\n";
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