// 树链剖分和虚树
#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
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
      if (v == fa[u])
        continue;
      fa[v] = u;
      dep[v] = dep[u] + 1;
      siz[u] += tree_build(v);
      if (son[u] == -1 || siz[v] > siz[son[u]])
        son[u] = v;
    }
    return siz[u];
  }
  void tree_decomposition(int u, int tp) {
    top[u] = tp, dfn[u] = ++tot, rnk[tot] = u;
    if (son[u] != -1) {
      tree_decomposition(son[u], tp);
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u])
          continue;
        tree_decomposition(v, v);
      }
    }
  }
  auto lca(int u, int v) {
    while (top[u] != top[v])
      if (dep[top[u]] > dep[top[v]])
        u = fa[top[u]];
      else
        v = fa[top[v]];
    return dep[u] > dep[v] ? v : u;
  }
};
struct virtual_tree {
  heavy_light_decomposition &G;
  vector<vector<int>> E;
  virtual_tree(heavy_light_decomposition &ptr) : G(ptr), E(ptr.n){};
  void build(vector<int> &node) {
    sort(node.begin(), node.end(),
         [&](int x, int y) { return G.dfn[x] < G.dfn[y]; });
    E[0].clear();
    stack<int> st;
    st.emplace(0);
    for (auto x : node) {
      E[x].clear();
      int top = G.lca(x, st.top());
      if (top == st.top()) {
        st.emplace(x);
        continue;
      }
      auto u = st.top();
      st.pop();
      while (!st.empty() && G.dep[st.top()] > G.dep[top]) {
        E[st.top()].emplace_back(u);
        u = st.top();
        st.pop();
      }
      if (!st.empty() && top == st.top()) {
        E[top].emplace_back(u);
      } else {
        E[top].clear();
        E[top].emplace_back(u);
        st.emplace(top);
      }
      st.emplace(x);
    }
    int u = st.top();
    st.pop();
    while (!st.empty()) {
      E[st.top()].emplace_back(u);
      u = st.top();
      st.pop();
    }
  }
};
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (auto &i : c)
    cin >> i;
  vector<vector<int>> col(n);
  for (int i = 0; i < n; ++i) {
    col[c[i] - 1].emplace_back(i);
  }
  heavy_light_decomposition G(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G.add_edge(u, v);
  }
  G.tree_build(0);
  G.tree_decomposition(0, 0);
  virtual_tree virt(G);
  vector<ll> num(n);
  ll ans = 0;
  for (int node = 0; node < n; ++node) {
    virt.build(col[node]);
    const auto &E = virt.E;
    function<void(int, int)> dfs = [&](int u, int fa) {
      num[u] = 0;
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        dfs(v, u);
        num[u] += num[v];
      }
      if (c[u] == node + 1) {
        ans += num[u];
        num[u] = 1;
      } else {
        ll cnt = 0;
        for (auto v : E[u]) {
          if (v == fa)
            continue;
          cnt += num[v] * (num[u] - num[v]);
        }
        ans += cnt / 2;
      }
    };
    dfs(0, 0);
  }
  cout << ans << "\n";
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