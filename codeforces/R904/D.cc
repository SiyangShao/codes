#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n), cnt(n + 1);
  for (auto &i : a) {
    cin >> i;
    cnt[i]++;
  }
  vector<ll> dp(n + 1), vis(n + 1);
  ll ans = 0;
  for (ll i = n; i >= 1; --i) {
    ll s = 0;
    for (ll j = i; j <= n; j += i) {
      s += cnt[j];
      dp[i] -= dp[j];
      if (cnt[i])
        vis[j] = 1;
    }
    dp[i] += s * (s - 1) / 2;
  }
  for (ll i = 1; i <= n; ++i) {
    if (!vis[i])
      ans += dp[i];
  }
  cout << ans << "\n";
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