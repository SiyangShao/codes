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
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edg(m);
  for (auto &[u, v] : edg) {
    cin >> u >> v;
    u--, v--;
  }
  DSU dsu(n);
  int k;
  cin >> k;
  vector<int> x(k);
  set<int> st;
  for (auto &i : x) {
    cin >> i;
    i--;
    st.emplace(i);
  }
  vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    auto [u, v] = edg[i];
    if (st.find(i) != st.end()) {
      deg[u]++, deg[v]++;
    } else {
      dsu.merge(u, v);
    }
  }
  int odd = 0;
  for (int i = 0; i < n; ++i) {
    if (deg[i] % 2 == 1) {
      odd++;
    }
  }
  if (odd % 2 == 1) {
    cout << "No\n";
    return;
  }
  set<int> cur;
  for (int i = 0; i < n; ++i) {
    if (deg[i] % 2 == 1) {
      if (cur.find(dsu.find(i)) != cur.end()) {
        cur.erase(dsu.find(i));
      } else {
        cur.emplace(dsu.find(i));
      }
    }
  }
  if (cur.empty() || cur.size() == 2) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
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