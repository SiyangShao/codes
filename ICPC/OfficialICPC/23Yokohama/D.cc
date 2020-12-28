#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
constexpr ll C = 242;
struct Hash {
  vector<ll> h, pw;
  Hash(string_view s) : h(s.length() + 1), pw(s.length() + 1) {
    pw[0] = 1;
    for (ll i = 1; i <= s.length(); ++i) {
      pw[i] = pw[i - 1] * C % MOD;
      h[i] = h[i - 1] * C % MOD + s[i - 1];
      h[i] %= MOD;
    }
  }
  ll interval(int a, int b) {
    return ((h[b] - h[a] * pw[b - a] % MOD) % MOD + MOD) % MOD;
  }
};
auto solve() {
  string s;
  cin >> s;
  Hash h(s);
  int n = (int)s.length();
  vector<vector<string>> dp(n, vector<string>(n));
  for (int i = 0; i < n; ++i) {
    string cur = "";
    for (int j = i; j < i + 4 && j < n; ++j) {
      cur += s[j];
      dp[i][j] = cur;
    }
  }
  for (int len = 5; len <= n; ++len) {
    for (int i = 0; i < n; ++i) {
      int j = i + len - 1;
      if (j >= n)
        continue;
      for (int k = i; k < j; ++k) {
        if (dp[i][j].length() == 0 ||
            dp[i][j].length() > dp[i][k].length() + dp[k + 1][j].length()) {
          dp[i][j] = dp[i][k] + dp[k + 1][j];
        }
      }
      for (int div = 2; div < 10; ++div) {
        if (len % div == 0) {
          int smallTack = len / div;
          bool flag = true;
          dbg("HERE!!!");
          for (int start = i + smallTack; start < j; start += smallTack) {
            if (dbg(h.interval(start, start + smallTack)) !=
                dbg(h.interval(i, i + smallTack))) {
              flag = false;
              break;
            }
          }
          dbg(flag);
          if (flag &&
              dp[i][j].length() > dp[i][i + smallTack - 1].length() + 3) {
            dp[i][j] = to_string(div) + "(" + dp[i][i + smallTack - 1] + ")";
          }
          dbg(dp[i][j]);
        }
      }
    }
  }
  dbg("HERE");
  dbg(dp);
  cout << dp[0][n - 1] << "\n";
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