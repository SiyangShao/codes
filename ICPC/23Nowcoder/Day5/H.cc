#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int maxn = 205;

int f[maxn][maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  vector dp(n, vector<vector<int>>(n, vector<int>(210)));
  for (int i = 0; i < n; ++i) {
    vector<int> cur(210, 0);
    for (int j = i; j < n; ++j) {
      for (int w = 200; w >= a[j]; --w) {
        cur[w] = max(cur[w], cur[w - a[j]] + b[j]);
      }
      dp[i][j] = cur;
    }
  }
  std::vector<int> tw(m);
  for (int i = 0; i < m; ++i) {
    cin >> tw[i];
  }
  std::reverse(tw.begin(), tw.end());
  std::vector<int> w;
  w.reserve(std::min(n, m));
  for (int i = 0; i < std::min(n, m); ++i) {
    w.push_back(tw[i]);
  }
  std::reverse(w.begin(), w.end());
  for (int i = 1; i <= min(n, m); ++i) {
    int siz = w[i - 1];
    for (int l = 1; l <= n; ++l) {
      f[i][l] = std::max(f[i][l], f[i - 1][l]);
      for (int r = l; r <= n; ++r) {
        f[i][r] = std::max(f[i][r], f[i - 1][l - 1] + dp[l - 1][r - 1][siz]);
      }
    }
  }
  std::cout << "====================\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cout << f[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << "====================\n";
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = std::max(ans, f[n][i]);
  }
  cout << ans << '\n';
  return 0;
}