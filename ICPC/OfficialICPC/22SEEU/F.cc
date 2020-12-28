#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
  int n;
  vector<int> fa;
  DSU(int _) : n(_), fa(_) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    assert(fa[u] <= u);
    if (u != fa[u]) {
      fa[u] = find(fa[u]);
    }
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return;
    if (u < v) {
      swap(u, v);
    }
    assert(v < u);
    fa[u] = v;
  }
};
auto solve() {
  int n;
  cin >> n;
  DSU dsu(n);
  vector<tuple<ll, int, int>> vec;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ll v;
      cin >> v;
      vec.emplace_back(v, i, j);
    }
  }
  vector<pair<ll, ll>> ans;
  sort(vec.begin(), vec.end(), greater<>());
  ll cnt = 0;
  for (auto &[w, u, v] : vec) {
    u = dsu.find(u), v = dsu.find(v);
    if (u == v)
      continue;
    cnt += w;
    ans.emplace_back(u, v);
    dsu.merge(u, v);
  }
  cout << cnt << "\n";
  for (auto &[u, v] : ans) {
    cout << u + 1 << " " << v + 1 << "\n";
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