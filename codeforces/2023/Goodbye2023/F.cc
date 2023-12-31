#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
struct Tarjan_BCC {
  int n, _t, edg_id;
  vector<vector<int>> E, child;
  vector<pair<int, int>> edges;
  vector<int> dfn, low, fa;
  vector<bool> cut;
  Tarjan_BCC(int _n)
      : n(_n), E(n), child(n), dfn(n, -1), low(n), fa(n, -1), cut(n, false) {
    edg_id = _t = 0;
  }
  void addEdge(int u, int v) {
    edges.emplace_back(u, v), E[u].emplace_back(edg_id),
        E[v].emplace_back(edg_id);
    edg_id++;
  }
  void dfs(int u, int fa_id) {
    low[u] = dfn[u] = _t++;
    for (auto id : E[u]) {
      auto v = edges[id].first ^ edges[id].second ^ u;
      if (id == fa_id)
        continue;
      if (dfn[v] != -1) {
        low[u] = min(low[u], dfn[v]);
      } else {
        fa[v] = u;
        dfs(v, id);
        child[u].emplace_back(v), low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u])
          cut[u] = true;
      }
    }
    if (fa_id == -1)
      cut[u] = child[u].size() > 1;
  }
  void solve() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1)
        dfs(i, -1);
    }
  }
  bool is_cut(int u) { return cut[u]; }
  vector<vector<int>> BCC_point() {
    vector<vector<int>> BCC;
    vector<int> tmp;
    vector<bool> vis(n, false);
    stack<int> st;
    function<void(int)> dfs = [&](int u) {
      st.emplace(u), vis[u] = true;
      for (auto v : child[u]) {
        dfs(v);
        if (low[v] >= dfn[u]) {
          tmp.clear();
          while (!st.empty() && st.top() != v) {
            tmp.emplace_back(st.top());
            st.pop();
          }
          tmp.emplace_back(st.top());
          st.pop(), tmp.emplace_back(u);
          BCC.emplace_back(tmp);
        }
      }
    };
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        if (child[i].empty())
          BCC.emplace_back(vector{i});
        dfs(i);
      }
    }
    return BCC;
  }
  bool is_bridge(int id) {
    return is_bridge(edges[id].first, edges[id].second);
  }
  bool is_bridge(int u, int v) { // assert there's an edge u-v
    if (dfn[u] > dfn[v])
      swap(u, v);
    return low[v] > dfn[u];
  }
  vector<vector<int>> BCC_edge() {
    vector<vector<int>> BCC;
    vector<int> tmp;
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int u) {
      vis[u] = true, tmp.emplace_back(u);
      for (auto id : E[u]) {
        auto v = edges[id].first ^ edges[id].second ^ u;
        if (!is_bridge(u, v) && !vis[v])
          dfs(v);
      }
    };
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        tmp.clear();
        dfs(i);
        BCC.emplace_back(tmp);
      }
    }
    return BCC;
  }
};
auto solve() {
  int n1, n2, m;
  cin >> n1 >> n2 >> m;
  vector<pair<int, int>> edg(m);
  vector<vector<int>> E(n1 + n2);
  vector<int> vis(n1 + n2, 0);
  for (auto &[u, v] : edg) {
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  vector<int> lef;
  lef.emplace_back(0);
  vis[0] = 1;
  for (int siz = 1; siz < n1; ++siz) {
    Tarjan_BCC G(n1 + n2);
    for (auto [u, v] : edg) {
      if (vis[u] || vis[v])
        continue;
      G.addEdge(u, v);
    }
    G.solve();
    for (auto u : lef) {
      for (auto v : E[u]) {
        if (vis[v])
          continue;
        if (!G.is_cut(v)) {
          lef.emplace_back(v);
          vis[v] = 1;
          goto OUT;
        }
      }
    }
    assert(false);
  OUT:
    continue;
  }
  for (int i = 0; i < n1 + n2; ++i) {
    if (vis[i]) {
      cout << i + 1 << " ";
    }
  }
  cout << "\n";
  for (int i = 0; i < n1 + n2; ++i) {
    if (!vis[i]) {
      cout << i + 1 << " ";
    }
  }
  cout << "\n";
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