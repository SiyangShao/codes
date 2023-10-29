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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector pref(n + 1, vector<int>(n + 1));
  vector suf(n + 1, vector<int>(n + 1));
  for (int l = 0; l < n; ++l) {
    int cnt = 0;
    for (int r = l + 1; r <= n; ++r) {
      cnt += s[r - 1] == '1';
      pref[r][cnt] = max(pref[r][cnt], r - l);
      suf[l][cnt] = max(suf[l][cnt], r - l);
    }
  }
  for (int r = 0; r <= n; ++r) {
    for (int cnt = 0; cnt <= n; ++cnt) {
      if (r > 0)
        pref[r][cnt] = max(pref[r][cnt], pref[r - 1][cnt]);
      if (cnt > 0)
        pref[r][cnt] = max(pref[r][cnt], pref[r][cnt - 1]);
    }
  }
  for (int l = n; l >= 0; --l) {
    for (int cnt = 0; cnt <= n; ++cnt) {
      if (l + 1 <= n)
        suf[l][cnt] = max(suf[l][cnt], suf[l + 1][cnt]);
      if (cnt > 0)
        suf[l][cnt] = max(suf[l][cnt], suf[l][cnt - 1]);
    }
  }
  vector<int> dp(n + 1, -1);
  for (int l = 0; l < n; ++l) {
    int cnt = 0;
    for (int r = l; r <= n; ++r) {
      if (r > l)
        cnt += s[r - 1] == '0';
      if (cnt > k)
        break;
      dp[r - l] = max(dp[r - l], pref[l][k - cnt]);
      dp[r - l] = max(dp[r - l], suf[r][k - cnt]);
    }
  }
  for (int a = 1; a <= n; ++a) {
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
      if (dp[i] == -1)
        continue;
      ans = max(ans, i + dp[i] * a);
    }
    cout << ans << " ";
  }
  cout << "\n";
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