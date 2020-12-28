#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) __VA_ARGS__
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
constexpr ll N = 1e7 + 1;
constexpr ll minN = 1e6 + 1;
array<ll, N> pre;
array<ll, minN> s;
auto solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    pre[s[i]] = 1;
  }
  ll mx = s[n];
  for (ll i = 1; i <= mx; ++i) {
    pre[i] += pre[i - 1];
  }
  ll ans = 0;
  for (ll x = 1; x <= mx; ++x) {
    ll p = mx / x, q = (mx + x - 1) / x;
    ll res = 0;
    if (p == q) {
      for (ll i = p; i <= mx; i += p) {
        res += pre[i] - pre[i - 1];
      }
    } else {
      for (ll i = 1; i * p <= mx; ++i) {
        if (i >= p) {
          res += dbg(pre[mx] - pre[dbg(i * p) - 1]);
          break;
        } else {
          res += dbg(pre[dbg(min(mx, i * p + i))] - pre[i * p - 1]);
        }
      }
    }
    dbg(x, res);
    ans += dbg(x * res % MOD);
    if (ans >= MOD)
      ans -= MOD;
  }
  cout << ans << "\n";
  for (ll i = 1; i <= mx; ++i) {
    pre[i] = 0;
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  fill(pre.begin(), pre.end(), 0);
  while (_--) {
    solve();
  }
}