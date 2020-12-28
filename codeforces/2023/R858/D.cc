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
  ll n;
  cin >> n;
  vector<int> a(n - 1);
  for (auto &i : a) {
    cin >> i;
  }
  vector<ll> dp(n, 0);
  dp[0] = 1;
  for (int i = 0; i < n - 1; ++i) {
    dp[i + 1] = dp[i] * (i - a[i] + 1) % MOD;
  }
  ll ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans = ans * (i + 1) % MOD + (a[i] == 0 ? dp[i] : 0);
    ans %= MOD;
    cout << ans << " ";
  }
  cout << "\n";
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