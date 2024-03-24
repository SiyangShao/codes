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
  vector<vector<int>> dp(n, vector<int>(n));
  vector<vector<pair<int, int>>> from(n, vector<pair<int, int>>(n, {-1, -1}));
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < i + 4 && j < n; ++j) {
      dp[i][j] = j - i + 1;
    }
  }
  for (int len = 5; len <= n; ++len) {
    for (int i = 0; i < n; ++i) {
      int j = i + len - 1;
      if (j >= n)
        continue;
      dp[i][j] = len;
      for (int k = i; k < j; ++k) {
        if (dp[i][j] > dp[i][k] + dp[k + 1][j]) {
          dp[i][j] = dp[i][k] + dp[k + 1][j];
          from[i][j] = {0, k};
        }
      }
      for (int div = 2; div < 10; ++div) {
        if (len % div == 0) {
          int smallTack = len / div;
          bool flag = true;
          for (int start = i + smallTack; start <= j; start += smallTack) {
            if (dbg(h.interval(start, start + smallTack)) !=
                dbg(h.interval(i, i + smallTack))) {
              flag = false;
              break;
            }
          }
          dbg(flag);
          if (flag && dp[i][j] > dp[i][i + smallTack - 1] + 3) {
            dp[i][j] = dp[i][i + smallTack - 1] + 3;
            from[i][j] = {1, smallTack};
          }
          dbg(dp[i][j]);
        }
      }
    }
  }
  dbg("HERE");
  dbg(dp);
  function<string(int, int)> build = [&](int i, int j) {
    int len = j - i + 1;
    if (from[i][j] == pair{-1, -1}) {
      return s.substr(i, len);
    }
    auto [type, k] = from[i][j];
    if (type == 1) {
      return to_string(len / k) + "(" + build(i, i + k - 1) + ")";
    } else {
      return build(i, k) + build(k + 1, j);
    }
  };
  cout << build(0, n - 1) << "\n";
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