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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  vector<ll> cnt(2 * k + 5, 0);
  for (ll i = 0; i < n / 2; i++) {
    ll l = min(a[i], a[n - i - 1]) + 1;
    ll cur = a[i] + a[n - i - 1];
    ll r = max(a[i], a[n - i - 1]) + k;
    cnt[2] += 2;
    cnt[l] -= 1;
    cnt[cur] -= 1;
    cnt[cur + 1] += 1;
    cnt[r + 1] += 1;
    cnt[2 * k + 1] -= 2;
  }
  ll tmp = 0, ans = 2 * n;
  for (ll i = 2; i <= 2 * k; i++) {
    tmp += cnt[i];
    ans = min(ans, tmp);
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