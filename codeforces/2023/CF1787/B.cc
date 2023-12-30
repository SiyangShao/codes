#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<ll, ll>> frac(ll n) {
  vector<pair<ll, ll>> result;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      ll cnt = 0;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      result.emplace_back(i, cnt);
    }
  }
  if (n != 1) {
    result.emplace_back(n, 1);
  }
  return result;
}
auto solve() {
  ll n;
  cin >> n;
  auto result = frac(n);
  ll ans = 0, cur = 1;
  sort(result.begin(), result.end(),
       [&](auto x, auto y) { return x.second > y.second; });
  while (result[0].second > 0) {
    cur = 1;
    for (auto &[l, r] : result) {
      if (r) {
        r--;
        cur *= l;
      } else {
        break;
      }
    }
    ans += cur;
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