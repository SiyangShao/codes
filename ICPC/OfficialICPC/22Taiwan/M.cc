#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
  int n;
  vector<int> fa;
  DSU(int _n) : n(_n), fa(_n) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return true;
    fa[u] = v;
    return false;
  }
};
auto solve() {
  int n;
  cin >> n;
  DSU dsu(1010);
  while (n--) {
    int p, q;
    cin >> p >> q;
    if (dsu.merge(p, q)) {
      cout << "Y\n";
    } else {
      cout << "N\n";
    }
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