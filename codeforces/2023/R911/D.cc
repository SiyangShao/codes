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
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  ranges::sort(a);
  constexpr int N = 1e5 + 7;
  vector<ll> cnt(N), num(N);
  for (int i = 0; i < n; ++i) {
    ll res = n - i - 1;
    for (int j = 1; j * j <= a[i]; ++j) {
      if (a[i] % j != 0)
        continue;
      cnt[j] += res * num[j];
      num[j]++;
      if (a[i] / j != j) {
        cnt[a[i] / j] += res * num[a[i] / j];
        num[a[i] / j]++;
      }
    }
  }
  ll ans = 0;
  for (ll i = N - 1; i >= 1; --i) {
    for (ll j = i * 2; j <= N - 1; j += i) {
      cnt[i] -= cnt[j];
    }
    ans += cnt[i] * i;
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