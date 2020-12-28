#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll sum = 0;
  sort(a.begin(), a.end());
  for (auto &i : a) {
    sum += i;
  }
  vector<ll> pre(k + 1, 0), aft(k + 1, 0);
  for (ll i = 0; i < k; ++i) {
    pre[i + 1] = pre[i] + a[i * 2] + a[i * 2 + 1];
    aft[i + 1] = aft[i] + a[n - i - 1];
  }
  ll ans = 0;
  for (ll i = 0; i <= k; ++i) {
    ans = max(ans, sum - pre[i] - aft[k - i]);
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