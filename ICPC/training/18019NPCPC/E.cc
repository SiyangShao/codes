#include <bits/stdc++.h>
int n, res, ans, cnt, lst;
bool can_add;
std::array<int, 100> a;
std::array<std::array<int, 5>, 100> dp;
void solve() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    // dp[i][0] = dp[i][1] = dp[i][2] = -1;
  }
  std::sort(a.begin(), a.begin() + n);
  ans = 1;
  for (int beg = 0; beg < n; ++beg) {
    lst = beg;
    dp[beg][0] = a[beg], dp[beg][1] = dp[beg][2] = a[beg] + 1;
    for (int i = beg + 1; i < n; ++i) {
      // From i-1 to i
      dp[i][0] = dp[i][1] = dp[i][2] = -1;
      for (int k = 0; k < 3; ++k) {
        if (dp[i - 1][k] == -1) {
          continue;
        }
        if (a[i] - dp[i - 1][k] <= 1) {
          dp[i][k] = (dp[i][k] > a[i] ? dp[i][k] : a[i]);
          dp[i][k + 1] =
              (dp[i][k + 1] > (a[i] + 1) ? dp[i][k + 1] : (a[i] + 1));
          // dp[i][k + 2] =
          //     (dp[i][k + 2] > (a[i] + 1) ? dp[i][k + 2] : (a[i] + 1));
        } else if (a[i] - dp[i - 1][k] == 2) {
          dp[i][k] = (dp[i][k] > a[i] ? dp[i][k] : a[i]);
          dp[i][k + 1] = (dp[i][k + 1] > (a[i]) ? dp[i][k + 1] : (a[i]));
          // dp[i][k + 2] = (dp[i][k + 2] > (a[i]) ? dp[i][k + 2] : (a[i]));
        } else if (a[i] - dp[i - 1][k] == 3) {
          dp[i][k] = (dp[i][k] > -1 ? dp[i][k] : -1);
          dp[i][k + 1] =
              (dp[i][k + 1] > (a[i] - 1) ? dp[i][k + 1] : (a[i] - 1));
          // dp[i][k + 2] =
          //     (dp[i][k + 2] > (a[i] - 1) ? dp[i][k + 2] : (a[i] - 1));
        }
      }
      if (dp[i][0] == -1 && dp[i][1] == -1 && dp[i][2] == -1) {
        break;
      }
      lst = i;
    }
    ans = ans > (lst - beg + 1) ? ans : (lst - beg + 1);
  }
  std::cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int _ = 1;
  std::cin >> _;
  int t = 0;
  while (_--) {
    std::cout << "Case " << ++t << ": ";
    solve();
  }
}