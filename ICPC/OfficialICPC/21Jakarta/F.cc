#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 1e6 + 7;
struct DSU {
  vector<int> fa, siz;
  vector<int> modi;
  DSU(int n) : fa(n), siz(n, 1) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u]) {
      fa[u] = find(fa[u]);
    }
    return fa[u];
  }
  void merge(int u, int v) {
    modi.emplace_back(u);
    modi.emplace_back(v);
    u = find(u), v = find(v);
    if (u == v)
      return;
    fa[u] = v;
    siz[v] += siz[u];
  }
  int reset() {
    int max_siz = 0;
    for (auto i : modi) {
      fa[i] = i;
      max_siz = max(max_siz, siz[i]);
      siz[i] = 1;
    }
    modi.clear();
    return max_siz;
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  bool flag = false;
  for (auto &i : a) {
    cin >> i;
    if (i != 1)
      flag = true;
  }
  vector<pair<int, int>> edg(n - 1);
  vector<vector<pair<int, int>>> frac(N);
  for (auto &[u, v] : edg) {
    cin >> u >> v;
    u--, v--;
    ll val = gcd(a[u], a[v]);
    for (ll i = 2; i * i <= val; ++i) {
      if (val % i == 0) {
        frac[i].emplace_back(u, v);
        while (val % i == 0) {
          val /= i;
        }
      }
    }
    if (val != 1) {
      frac[val].emplace_back(u, v);
    }
  }
  DSU dsu(n);
  int ans = 0;
  if (flag)
    ans = 1;
  for (int i = 2; i < N; ++i) {
    for (auto [u, v] : frac[i]) {
      dsu.merge(u, v);
    }
    ans = max(ans, dsu.reset());
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