#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
  int n;
  vector<int> fa, siz, L, R;
  vector<ll> val;
  DSU(int _) : n(_), fa(_), siz(_, 1), L(_), R(_), val(_,0) {
    iota(fa.begin(), fa.end(), 0);
    for (int i = 0; i < n; ++i) {
      L[i] = R[i] = fa[i];
    }
  }
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
    val[u] = min(val[u], val[v]);
    val[v] = min(val[u], val[v]);
    fa[u] = v;
    siz[v] += siz[u];
    L[v] = min(L[u], L[v]), R[v] = max(R[v], R[u]);
    return true;
  }
  int size(int u) { return siz[find(u)]; }
  ll getVal(int u) { return val[find(u)]; };
  int getLeft(int u) { return L[find(u)] - 1; }
  int getRight(int u) { return R[find(u)] + 1; }
};
auto solve() {
  int n;
  cin >> n;
  vector<int> id(n);
  vector<ll> c(n + 1);
  DSU dsu(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    dsu.val[i] = c[i];
    id[i - 1] = i;
  }
  sort(id.begin(), id.end(), [&](int u, int v) { return c[u] > c[v]; });
  ll ans = 0;
  for (auto x : id) {
    int L = dsu.getLeft(x), R = dsu.getRight(x);
    if(L == 0 && R == n+1){
      ans += dsu.getVal(x) * ((dsu.size(x) + 1) / 2);
    }else{
      if (R == n + 1 || (c[L] != 0 && c[L] >= c[R])) {
        ans += (dsu.getVal(x) - dsu.getVal(L)) * ((dsu.size(x) + 1) / 2);
        dsu.merge(L, x);
      } else {
        ans += (dsu.getVal(x) - dsu.getVal(R)) * ((dsu.size(x) + 1) / 2);
        dsu.merge(R, x);
      }
    }
  }
  cout << ans << "\n";
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