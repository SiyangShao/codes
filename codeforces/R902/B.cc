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
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; --i) {
    for (int j = i; j <= n; j += i) {
      a[i] = max(a[i], a[j]);
    }
  }
  dbg(a);
  vector<ll> b(n);
  for (int i = 1; i <= n; ++i) {
    b[i - 1] = a[i];
  }
  ranges::sort(b);
  ll ans = 0, bs = 1;
  for(int i = 0 ;i < n ;++i){
    ans += b[i] * bs% MOD;
    ans %= MOD;
    bs = bs * 2 % MOD;
  }
  cout<<ans<<"\n";
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