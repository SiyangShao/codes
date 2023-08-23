#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct heavy_light_decomposition {
  int n, m, s, tot;
  vector<int> fa, dep, siz, son, top, dfn, rnk, lst;
  // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
  // top: top of path, dfn: dfs number, rnk: rank of dfs number
  vector<vector<int>> E;
  heavy_light_decomposition(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), lst(_n), E(_n) {
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
    lst[u] = tot + 1;
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
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  heavy_light_decomposition G(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G.add_edge(u, v);
  }
  G.tree_build(0);
  G.tree_decomposition(0, 0);
  vector dp(n, vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 1;
  }
  function<int(int, int)> find_next = [&](int l, int r) {
    // assert l is the ancestor of r
    assert(G.dfn[l] <= G.dfn[r] && G.lst[l] > G.dfn[r]);
    // cout<<G.dfn[l]<<" "<<G.dfn[r]<<" "<<G.lst[l]<<" "<<l+1<<" "<<r+1<<endl;
    for (auto v : G.E[l]) {
      if (v == G.fa[l])
        continue;
      if (G.dfn[v] <= G.dfn[r] && G.lst[v] > G.dfn[r])
        return v;
    }
    assert(false);
  };
  function<int(int, int)> dfs = [&](int l, int r) {
    if (dp[l][r] != -1) {
      return dp[l][r];
    }
    if (dp[r][l] != -1) {
      return dp[r][l];
    }
    auto lca = G.lca(l, r);
    if (s[l] == s[r]) {
      if (lca != l && lca != r) {
        dp[l][r] = dfs(G.fa[l], G.fa[r]) + 2;
      } else if (lca == l) {
        if (G.fa[r] == l)
          dp[l][r] = 2;
        else {
          dp[l][r] = 2 + dfs(find_next(l, r), G.fa[r]);
        }
      } else {
        if (G.fa[l] == r)
          dp[l][r] = 2;
        else {
          dp[l][r] = 2 + dfs(G.fa[l], find_next(r, l));
        }
      }
    } else {
      if (lca != l && lca != r) {
        dp[l][r] = max(dfs(G.fa[l], r), dfs(l, G.fa[r]));
      } else if (lca == l) {
        if (G.fa[r] == l)
          dp[l][r] = 1;
        else {
          dp[l][r] = dfs(find_next(l, r), r);
          dp[l][r] = max(dp[l][r], dfs(l, G.fa[r]));
        }
      } else {
        if (G.fa[l] == r)
          dp[l][r] = 1;
        else {
          dp[l][r] = dfs(l, find_next(r, l));
          dp[l][r] = max(dp[l][r], dfs(G.fa[l], r));
        }
      }
    }
    // cout << l + 1 << " " << r + 1 <<" "<<dp[l][r]<< endl;
    return dp[l][r];
  };
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dfs(i, j);
      ans = max(ans, dp[i][j]);
      // cout<<i<<" "<<j<<" ";
      // cout<<dp[i][j]<<"\n";
    }
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}