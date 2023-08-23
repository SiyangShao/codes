#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
  int n;
  vector<int> fa, size;
  DSU(int _) : n(_), fa(_), size(_, 1) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u]) {
      fa[u] = find(fa[u]);
    }
    return fa[u];
  }
  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return false;
    if (size[u] < size[v]) {
      swap(u, v);
    }
    fa[v] = u;
    size[u] += size[v];
    return true;
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  DSU dsu(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  for (int i = 0; i < n; ++i) {
    dsu.merge(a[i], i);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (dsu.find(i) == i) {
      ans += dsu.size[i] - 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if ((i > 0 && dsu.find(i) == dsu.find(i - 1)) ||
        (i + 1 < n && dsu.find(i) == dsu.find(i + 1))) {
      cout << ans - 1 << "\n";
      return;
    }
  }
  cout << ans + 1 << "\n";
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
