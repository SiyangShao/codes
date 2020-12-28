// 树链剖分和虚树
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
      if (v == fa[u]) continue;
      fa[v] = u;
      dep[v] = dep[u] + 1;
      siz[u] += tree_build(v);
      if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
    }
    return siz[u];
  }
  void tree_decomposition(int u, int tp) {
    top[u] = tp, dfn[u] = ++tot, rnk[tot] = u;
    if (son[u] != -1) {
      tree_decomposition(son[u], tp);
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u]) continue;
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