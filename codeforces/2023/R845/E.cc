#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
  int n;
  vector<int> fa;
  DSU(int _) : n(_), fa(_) { iota(fa.begin(), fa.end(), 0); };
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  bool isSame(int u, int v) { return find(u) == find(v); }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
struct Tarjan_SCC {
  int n, edg_id, _t, sc_id;
  vector<vector<int>> E, scc;
  vector<pair<int, int>> edges;
  vector<int> dfn, low, in_scc;
  stack<int> st;
  vector<bool> in_st;
  Tarjan_SCC(int _n)
      : n(_n), E(_n), dfn(_n, -1), low(_n), in_scc(_n, -1), in_st(_n, false) {
    sc_id = edg_id = _t = 0;
  }
  void addEdge(int u, int v) {
    edges.emplace_back(u, v), E[u].emplace_back(edg_id);
    // E[v].emplace_back(edg_id);
    edg_id++;
  }
  void dfs(int u) {
    low[u] = dfn[u] = _t++;
    st.emplace(u), in_st[u] = true;
    for (auto id : E[u]) {
      auto v = edges[id].second;
      if (dfn[v] == -1) {
        dfs(v);
        low[u] = min(low[u], low[v]);
      } else if (in_st[v]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (dfn[u] == low[u]) {
      vector<int> _scc;
      _scc.clear();
      while (st.top() != u) {
        auto v = st.top();
        in_scc[v] = sc_id, _scc.emplace_back(v), in_st[v] = false;
        st.pop();
      }
      in_scc[u] = sc_id, _scc.emplace_back(u);
      scc.emplace_back(_scc);
      sc_id++;
      st.pop(), in_st[u] = false;
    }
  }
  void solve() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1) {
        dfs(i);
      }
    }
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  vector<tuple<int, int, ll>> edg(m);
  ll l = 0, r = 0;
  for (auto &[u, v, w] : edg) {
    cin >> u >> v >> w;
    r = max(r, w);
    u--, v--;
    dsu.merge(u, v);
  }
  for (int i = 1; i < n; ++i) {
    if (!dsu.isSame(i, i - 1)) {
      cout << "-1\n";
      return;
    }
  }
  auto check = [&](ll val) {
    Tarjan_SCC G(n);
    for (auto &[u, v, w] : edg) {
      if (w <= val) {
        G.addEdge(u, v);
        G.addEdge(v, u);
      } else {
        G.addEdge(u, v);
      }
    }
    G.solve();
    vector<int> in(G.sc_id, 0);
    for (auto &[u, v, w] : edg) {
      if (G.in_scc[u] == G.in_scc[v])
        continue;
      in[G.in_scc[v]]++;
    }
    int ans = 0;
    for (int i = 0; i < G.sc_id; ++i) {
      if (in[i] == 0) {
        ans++;
      }
    }
    return ans <= 1;
  };
  ll ans = r;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
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