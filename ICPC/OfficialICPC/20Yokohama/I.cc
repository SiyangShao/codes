#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
auto solve() {
  int n;
  cin >> n;
  vector<pair<string, int>> op(n * 2);
  vector<int> status(n, -1); // -1: uncalled
  int out_no_in = 0, in_no_out = 0, don_care = 0, other = 0;
  for (auto &[u, v] : op) {
    cin >> u >> v;
    v--;
    if (v == -1)
      continue;
    if (u == "I") {
      in_no_out++;
      status[v] = 1;
    } else if (u == "O") {
      if (status[v] == 1) {
        in_no_out--;
        don_care++;
        status[v] = 0; // dont care
      } else {
        out_no_in++;
        status[v] = 2; // out without in
      }
    }
  }
  other = n - out_no_in - in_no_out - don_care;
  vector<ll> dp(out_no_in + 1, 0); // dp[i]: has selected i out_no_in's solution
  int in_chance = 0;
  int sum_in = 0;
  dp[0] = 1;
  int already_out = 0;
  for (auto [x, u] : op) {
    if (u != -1 && status[u] == 0)
      continue;
    if (u == -1) {
      if (x == "I") {
        vector<ll> nxt(out_no_in + 1, 0);
        for (int i = 0; i <= min(in_chance, out_no_in); ++i) {
          if (other - (in_chance - i) >= 0) {
            nxt[i] = dp[i] * (other - (in_chance - i)) % MOD;
          }
          nxt[i] += (i == 0 ? 0 : dp[i - 1]);
          nxt[i] %= MOD;
        }
        if (in_chance + 1 <= out_no_in) {
          nxt[in_chance + 1] = dp[in_chance];
        }
        in_chance++;
        sum_in++;
        dp = nxt;
      } else {
        for (int i = 0; i <= out_no_in; ++i) {
          dp[i] = dp[i] * max(sum_in - i, 0) % MOD;
        }
        sum_in--;
      }
    } else {
      if (x == "I") {
        sum_in++;
      } else {
        auto nxt = dp;
        for (int i = 0; i <= out_no_in; ++i) {
          nxt[i] = (i <= already_out ? 0 : dp[i] * (i - already_out) % MOD);
        }
        already_out++;
        dp = nxt;
      }
    }
    dbg(x, u + 1);
    dbg(dp);
  }
  cout << dp[out_no_in] << "\n";
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