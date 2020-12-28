#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<ll> x(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  sort(x.begin() + 1, x.end());
  vector<pair<ll, int>> h(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> h[i].first >> h[i].second;
  }
  sort(h.begin() + 1, h.end());
  vector dp(m + 1, vector<ll>(n + 1, inf));
  vector<ll> presum(n + 1);
  function<void(int)> cal_presum = [&](int j) {
    presum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      presum[i] = presum[i - 1] + abs(x[i] - h[j].first);
    }
  };
  function<void(int, int, int, int, int)> cal = [&](int l, int r, int L, int R,
                                                    int j) {
    if (l > r || L > R)
      return;
    int mid = (l + r) / 2;
    int pos = min(R, mid);
    dp[j][mid] = dp[j - 1][mid];
    for (int i = max(L, mid - h[j].second); i <= min(R, mid); ++i) {
      if (dp[j][mid] > dp[j - 1][i] + presum[mid] - presum[i]) {
        dp[j][mid] = dp[j - 1][i] + presum[mid] - presum[i];
        pos = i;
      }
    }
    cal(l, mid - 1, L, pos, j);
    cal(mid + 1, r, pos, R, j);
  };
  dp[0][0] = 0;
  for (int i = 1; i <= m; ++i) {
    cal_presum(i);
    dp[i][0] = 0;
    cal(1, n, 0, n, i);
    // for (int j = 1; j <= n; ++j) {
    //   for (int k = max(0, j - h[i].second); k <= j; ++k) {
    //     dp[i][j] = min(dp[i][j], presum[j] - presum[k] + dp[i - 1][k]);
    //   }
    // }
  }
  if (dp[m][n] >= inf) {
    cout << "-1\n";
  } else {
    cout << dp[m][n] << "\n";
  }
}