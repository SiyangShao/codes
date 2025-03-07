#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector mp(n, vector<int>(m));
  for (auto &i : mp) {
    for (auto &j : i) {
      cin >> j;
      if (j > 0)
        j--;
    }
  }
  ll ans = 0;
  {
    vector<int> cnt(k);
    for (int i = 1; i < n; i++) {
      for (auto j : mp[i - 1]) {
        if (~j)
          cnt[j]++;
      }
      for (auto j : mp[i]) {
        if (~j) {
          ans += cnt[j];
        }
      }
      for (auto j : mp[i - 1]) {
        if (~j)
          cnt[j]--;
      }
    }
  }
  vector<int> neg(n);
  for (int i = 0; i < n; i++) {
    neg[i] = int(count(mp[i].begin(), mp[i].end(), -1));
  }
  vector<ll> dp(k);
  vector<int> cnt(k);
  ll mx = 0, a = 0, b = 0;
  for (int i = 1; i < n; i++) {
    for (auto x : mp[i]) {
      if (~x)
        cnt[x]++;
    }
    for (auto x : mp[i]) {
      if (~x && cnt[x]) {
        dp[x] = max(dp[x], a) + 1LL * neg[i - 1] * cnt[x];
        mx = max(mx, dp[x]);
        cnt[x] = 0;
      }
    }
    for()
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
