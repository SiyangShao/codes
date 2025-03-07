#include <bits/stdc++.h>
using namespace std;
using ll = int;
constexpr ll inf = 5e8;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector mp(n, vector<vector<ll>>(n, vector<ll>(n)));
  for (auto &i : mp) {
    for (auto &j : i) {
      for (auto &k : j) {
        cin >> k;
      }
    }
  }
  vector dp(1 << n, vector<ll>(1 << n, inf));
  dp[0][0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      if (i == 0 && j == 0)
        continue;
      if (__popcount(i) != __popcount(j)) {
        continue;
      }
      int layer = __popcount(i);
      vector<int> a, b;
      for (int k = 0; k < n; ++k) {
        if ((i >> k) & 1) {
          a.emplace_back(k);
        }
        if ((j >> k) & 1) {
          b.emplace_back(k);
        }
      }
      for (auto x : a) {
        for (auto y : b) {
          dp[i][j] = min(dp[i][j],
                         dp[i - (1 << x)][j - (1 << y)] + mp[layer - 1][x][y]);
        }
      }
    }
  }
  cout << dp[(1 << n) - 1][(1 << n) - 1] << "\n";
}
