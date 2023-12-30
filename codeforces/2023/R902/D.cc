#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
struct DSU {
  vector<int> fa;
  DSU(int n) : fa(n) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return false;
    fa[u] = v;
    return true;
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt, id;
  for (auto &i : a) {
    cin >> i;
    cnt[i]++;
  }
  ll ans = 1;
  int tot = 0;
  bool flag = true;
  for (auto [i, j] : cnt) {
    ans = ans * 2 % MOD;
    id[i] = tot++;
    if (j % 2) {
      flag = false;
    }
  }
  if (flag) {
    DSU dsu(tot);
    vector<int> x, y;
    vector<int> cur(tot);
    int num = tot;
    const int mx = tot;
    for (int i = 0, j = 0; i < n; ++i) {
      if (cur[id[a[i]]] % 2 == 0) {
        x.emplace_back(id[a[i]]);
      } else {
        y.emplace_back(id[a[i]]);
      }
      num -= cur[id[a[i]]] % 2 == 0;
      cur[id[a[i]]]++;
      num += cur[id[a[i]]] % 2 == 0;
      if (num == mx) {
        for (int k = j; k < i; ++k) {
          tot -= dsu.merge(id[a[k]], id[a[k + 1]]);
        }
        j = i + 1;
      }
    }
    if (x == y) {
      ans = (ans + MOD - qpow(2, tot)) % MOD;
    }
  }
  ans = ans * qpow(2, MOD - 2) % MOD;
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