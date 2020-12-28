#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
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
  void rebuild() {
    fill(dfn.begin(), dfn.end(), -1);
    fill(low.begin(), low.end(), 0);
    fill(in_scc.begin(), in_scc.end(), -1);
    fill(in_st.begin(), in_st.end(), false);
    sc_id = _t = 0;
    scc.clear();
    while (!st.empty())
      st.pop();
  }
  void addEdge(int u, int v) {
    edges.emplace_back(u, v), E[u].emplace_back(edg_id++);
  }
  void dfs(int u) {
    low[u] = dfn[u] = _t++;
    st.emplace(u), in_st[u] = true;
    for (auto id : E[u]) {
      auto v = edges[id].second;
      if (dfn[v] == -1)
        dfs(v), low[u] = min(low[u], low[v]);
      else if (in_st[v])
        low[u] = min(low[u], dfn[v]);
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
    for (int i = 0; i < n; ++i)
      if (dfn[i] == -1)
        dfs(i);
  }
};
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n))
    x++;
  return x;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edg(m);
  for (auto &[u, v] : edg) {
    cin >> u >> v;
    u--, v--;
  }
  vector<int> a(n);
  iota(a.begin(), a.end(), 0);
  // for (auto &i : a)
  //   cin >> i;
  const int log = ceil_pow2(n), size = 1 << log;
  Tarjan_SCC G(size * 4);
  stack<int> st;
  auto either = [&](int x, int y) {
    G.addEdge(x ^ 1, y);
    G.addEdge(y ^ 1, x);
    st.emplace(x ^ 1);
    st.emplace(y ^ 1);
  };
  auto nxt = [&](int x, int y) { either(x ^ 1, y); };
  // auto must = [&](int x) { either(x, x); };
  for (int i = size - 1; i >= 1; --i) {
    nxt((i * 2) ^ 1, ((i * 2) * 2) ^ 1);
    nxt((i * 2) ^ 1, ((i * 2 + 1) * 2) ^ 1);
  }

  for (const auto &[u, v] : edg) {
    either((u + size) * 2, (v + size) * 2);
  }
  while (!st.empty())
    st.pop();
  auto addRange = [&](int x, int l, int r) {
    if (l == r)
      return;
    l += size, r += size, x += size;
    while (l < r) {
      if (l & 1) {
        nxt(x * 2, ((l++) * 2) ^ 1);
      }
      if (r & 1) {
        nxt(x * 2, ((--r) * 2) ^ 1);
      }
      l >>= 1;
      r >>= 1;
    }
  };
  auto check = [&](int dif) {
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
      while (l <= i - dif)
        l++;
      while (r < i + dif)
        r++;

      r = min(r, n);
      addRange(i, l, i);
      addRange(i, i + 1, r);
    }
    G.solve();
    bool ans = true;
    for (int i = 1; i < size * 2; ++i) {
      if (G.in_scc[(i * 2)] == G.in_scc[(i * 2) ^ 1]) {
        ans = false;
        break;
      }
    }
    while (!st.empty()) {
      auto u = st.top();
      G.edges.pop_back();
      G.E[u].pop_back();
      st.pop();
      G.edg_id--;
    }
    G.rebuild();
    return ans;
  };
  int l = 0, r = n;
  int ans = 0;
  // for (int i = 0; i <= n; ++i) {
  //   dbg(check(i));
  // }
  while (l <= r) {
    int mid = (l + r) / 2;
    if (dbg(check(dbg(mid)))) {
      l = mid + 1;
      ans = max(ans, mid);
    } else {
      r = mid - 1;
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