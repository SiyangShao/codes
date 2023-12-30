#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  ranges::sort(a);
  ranges::sort(b);
  vector<ll> gt(n);
  ll ans = 1;
  for (ll i = 0; i < n; ++i) {
    gt[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    if (gt[i] <= i) {
      cout << "0\n";
      return;
    }
    ans = ans * (gt[i] - i) % MOD;
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