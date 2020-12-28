#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> p(m);
  vector<vector<int>> g(n + 1);
  for (auto &[l, r] : p) {
    cin >> l >> r;
  }
  // process p
  sort(p.begin(), p.end());
  vector<int> allOne(n + 2, 0), allZero(n + 2, 0);
  vector<int> status(n + 1, -1);
  {
    int curL = 0, curR = 0;
    for (auto [l, r] : p) {
      if (curL == 0) {
        curL = l, curR = r;
        continue;
      }
      if (l > curR) {
        g[curL].emplace_back(curR);
        curL = l, curR = r;
      } else {
        // overlap
        // curL - l - curR - r
        assert(l >= curL);
        if (r > curR) {
          // l-curR is real, curR to r is all 1, curL to l is all 0
          allOne[curR] += 1;
          allOne[r + 1] += -1;
          allZero[curL] += 1;
          allZero[l + 1] += -1;
          curL = l;
        } else {
          // real is l-r, curL - l is all 0, r to curR is all 1
          allOne[r] += 1;
          allOne[curR + 1] += -1;
          allZero[curL] += 1;
          allZero[l + 1] += -1;
          curL = l, curR = r;
        }
        dbg(allOne, allZero, curL, curR);
      }
    }
    if (curL) {
      g[curL].emplace_back(curR);
    }
    dbg(allOne, allZero, p);
    int base1 = 0, base0 = 0;
    for (int i = 1; i <= n; ++i) {
      base1 += allOne[i];
      base0 += allZero[i];
      if (base1 && base0) {
        cout << "-1\n";
        return;
      } else if (base1) {
        status[i] = 1;
      } else if(base0){
        status[i] = 0;
      }
    }
  }

  vector dp(n + 1, vector<ll>(n + 1, -inf));
  dp[0][0] = 0;
  dbg(status);
  for (int i = 1; i <= n; ++i) {
    // consider all number from 1 to i, has j 1, number of 1-0
    if (g[i].empty()) {
      // a[i] could be 0 or 1. doesn't matter
      if (status[i] == 0 || status[i] == -1)
        for (int j = 0; j < i; ++j) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j] + j);
        }
      // a[i] be 1:
      if (status[i] == 1 || status[i] == -1)
        for (int j = 1; j <= i; ++j) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        }
    } else {
      assert(g[i].size() == 1);
      int l = i, r = g[i][0];
      int left_most_one = r, right_most_zero = l;
      for (int j = l; j <= r; ++j) {
        if (status[j] == 1) {
          left_most_one = min(left_most_one, j);
        } else if (status[j] == 0) {
          right_most_zero = max(right_most_zero, j);
        }
      }
      if (left_most_one <= right_most_zero) {
        cout << "-1\n";
        return;
      }
      dbg(l, r, left_most_one, right_most_zero);
      l = right_most_zero, r = left_most_one;
      for (int num_zero = 1; num_zero <= r - l; ++num_zero) {
        int num_one = r - l + 1 - num_zero;
        dbg(num_zero, num_one);
        for (int j = 0; j <= l - 1; ++j) {
          dp[r][j + num_one] =
              max(dp[r][j + num_one], dbg(dp[l - 1][j] + (ll)j * num_zero));
        }
      }
      i = g[i][0];
    }
    dbg(i, dp[i]);
  }
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    ll res = dp[n][i] + (ll)i * (i - 1) / 2 + (ll)(n - i) * (n - i - 1) / 2;
    ans = max(ans, res);
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