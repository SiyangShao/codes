#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
bool is_prime(ll x) {
  for (ll i = 2; i * i <= x; ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<array<int, 4>> dp(n);
  dp[0][0] = 0;
  dp[0][1] = dp[0][2] = dp[0][3] = 1;
  if (a[0] == 1) {
    dp[0][1] = 0;
  }
  auto update0 = [&](int i) {
    if (is_prime(a[i] + a[i - 1]))
      dp[i][0] = dp[i - 1][0];
    else
      dp[i][0] = inf;
    if (is_prime(a[i] + 1)) {
      dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    }
    if (a[i] % 2 == 0) {
      dp[i][0] = min(dp[i][0], dp[i - 1][3]);
    } else {
      dp[i][0] = min(dp[i][0], dp[i - 1][2]);
    }
  };
  auto update1 = [&](int i) {
    if (is_prime(a[i - 1] + 1)) {
      dp[i][1] = dp[i - 1][0] + (a[i] != 1 ? 1 : 0);
    } else {
      dp[i][1] = inf;
    }
    dp[i][1] = min(dp[i][1], dp[i - 1][1] + (a[i] != 1 ? 1 : 0));
    dp[i][1] = min(dp[i][1], dp[i - 1][2] + (a[i] != 1 ? 1 : 0));
  };
  auto update2 = [&](int i) {
    dp[i][2] = inf;
    dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);
    dp[i][2] = min(dp[i][2], dp[i - 1][3] + 1);
    if (a[i - 1] % 2 == 1) {
      dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
    }
  };
  auto update3 = [&](int i) {
    dp[i][3] = inf;
    dp[i][3] = min(dp[i][3], dp[i - 1][2] + 1);
    if (a[i - 1] % 2 == 0) {
      dp[i][3] = min(dp[i][3], dp[i - 1][0] + 1);
    }
  };
  for (int i = 1; i < n; ++i) {
    update0(i);
    update1(i);
    update2(i);
    update3(i);
    if (a[i] == 1) {
      auto mx = min(dp[i][0], dp[i][1]);
      dp[i][0] = dp[i][1] = mx;
    }
  }
  cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]}) << "\n";
}