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
  for (auto &arr : b) {
    const ll siz = arr.size();
    const auto bs = arr;
    dp[siz] = 0;
    for (ll i = 0; i < siz; ++i) {
      dp[i] = 1e16;
    }
    for (ll i = siz - 1; i >= 0; --i) {
      ll tmp = 0;
      arr = bs;
      for (ll j = i; j < siz; ++j) {
        if (arr[j] != 0) {
          tmp++;
          if (j + 1 != siz) {
            arr[j + 1] ^= arr[j];
          }
        }
        dp[i] = min(dp[i], tmp + dp[j + 1]);
      }
    }
    op += dp[0];
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