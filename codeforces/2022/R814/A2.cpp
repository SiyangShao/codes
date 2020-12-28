#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<ll>> b;
  vector<ll> tmp;
  for (auto i : a) {
    if (i == 0) {
      if (!tmp.empty()) {
        b.emplace_back(tmp);
        tmp.clear();
      }
    } else {
      tmp.emplace_back(i);
    }
  }
  if (!tmp.empty()) {
    b.emplace_back(tmp);
  }
  ll op = 0;
  vector<ll> dp(n + 1, 0);
  map<ll, ll> mp;
  for (auto &arr : b) {
    const ll siz = arr.size();
    ll cur = 0;
    mp.clear();
    mp[0] = 0;
    dp[0] = 0;
    for (ll i = 1; i <= siz; ++i) {
      cur ^= arr[i - 1];
      if (i == 0) {
        dp[i] = 1;
      } else {
        dp[i] = dp[i - 1] + 1;
      }
      if (mp.find(cur) != mp.end()) {
        dp[i] = min(dp[i], (i - mp[cur] - 1) + dp[mp[cur]]);
      }
      mp[cur] = i;
    }
    op += dp[siz];
  }
  cout << op << "\n";
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