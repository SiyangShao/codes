#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ranges::sort(a);
  vector<ll> dp(n + 1, inf);
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = min(dp[i] + 1, a[i] + 1);
  }
  ll sum = accumulate(a.begin(), a.end(), 0LL);
  while (q--) {
    ll k;
    cin >> k;
    if (k < n) {
      cout << min(dp[k], a[k]) << " ";
    } else {
      ll x = sum;
      if ((k - n) % 2 == 0) {
        x += (k + k - n + 1) * (ll)n / 2 - (k - n) / 2;
        cout << min(dp[n] + k - n, x >= 0 ? x / n : (x - n + 1) / n);
      } else {
        x += (n - 1LL) * (k + k - n + 2) / 2 - (k - n + 1) / 2;
        cout << min({a[n - 1], dp[n - 1] + k - (n - 1),
                     x >= 0 ? x / n : (x - n + 1) / n});
      }
      cout << " ";
    }
  }
  cout << "\n";
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