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
  int n;
  cin >> n;
  constexpr ll inf = 1e9;
  // dp[i][j][k], first i, j non-check, k coin, total val
  vector<ll> nxt(n + 1, -inf), cur(n + 1, -inf);
  cur[0] = 0;
  // cur[i]: current attack is i, max money
  int base = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "B") {
      // 1. buy
      base++;
      for (int j = 0; j <= n; ++j) {
        nxt[j] = cur[j];
      }
      for (int j = 0; j < n; ++j) {
        if (cur[j] > 0) {
          nxt[j + 1] = max(nxt[j + 1], cur[j] - 1);
        }
      }
    } else {
      int a, b;
      cin >> a >> b;
      // choose a
      for (int j = 0; j <= n; ++j) {
        int res = base - j;
        if (res < 0)
          break;
        res = min(res, a);
        nxt[j + res] = max(nxt[j + res], cur[j]);
      }
      // choose b
      for (int j = 0; j <= n; ++j) {
        nxt[j] = max(nxt[j], cur[j] + b);
      }
    }
    swap(cur, nxt);
    fill(nxt.begin(), nxt.end(), -inf);
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (cur[i] >= 0) {
      ans = max(ans, i + base);
    }
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