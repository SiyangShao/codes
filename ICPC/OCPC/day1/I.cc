#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mp(n + 1, vector<int>(m + 1, 0));
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
  vector<vector<bool>> L(n + 1, vector<bool>(m + 1, true));
  auto R = L, U = L, D = L;
  bool flag = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mp[i][j];
      if (mp[i][j] == i + j - 1) {
        mp[i][j] = 0;
        R[i][j - 1] = false;
        D[i - 1][j] = false;
      } else if (mp[i][j] == i + j) {
        mp[i][j] = 1;
        L[i][j] = false;
        U[i][j] = false;
      } else if (mp[i][j] != -1) {
        flag = false;
      }
    }
  }
  if (!flag) {
    cout << "0\n";
    return;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      L[i][j] = L[i][j] && L[i][j - 1];
    }
    for (int j = m - 1; j >= 0; --j) {
      R[i][j] = R[i][j] && R[i][j + 1];
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = n - 1; i >= 0; --i) {
      D[i][j] = D[i][j] && D[i + 1][j];
    }
    for (int i = 1; i <= n; ++i) {
      U[i][j] = U[i][j] && U[i - 1][j];
    }
  }
  dp[n][0] = 1;
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j <= m; ++j) {
      // cout << mp[i][j] << " " << L[i][j] << " " << R[i][j] << " " << D[i][j]
      //  << " " << U[i][j] << "\n";
      // cout<<dp[i][j]<<" ";
      if (i - 1 >= 0) {
        if (L[i][j] && R[i][j]) {
          dp[i - 1][j] = (dp[i - 1][j] + dp[i][j]) % MOD;
        }
      }
      if (j + 1 <= m) {
        if (U[i][j + 1] && D[i][j + 1]) {
          dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
        }
      }
    }
  }
  cout << dp[0][m] << "\n";
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