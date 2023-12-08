#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  vector<int> vis(m);
  vector<int> dp(m, 1);
  vector<int> ans(n);
  int res = m;
  for (int cur = 0; cur <= 2 * n; cur++) {
    int i = cur % n;
    if (!vis[a[i]]) {
      vis[a[i]] = 1;
      if (!vis[b[i]]) {
        dp[b[i]] += dp[a[i]];
        dp[a[i]] = 0;
      } else {
        ans[i] = dp[a[i]];
        res -= dp[a[i]];
        dp[a[i]] = 0;
      }
    } else if (!vis[b[i]]) {
      vis[b[i]] = 1;
      ans[i] = dp[b[i]];
      res -= dp[b[i]];
      dp[b[i]] = 0;
    } else {
      ans[i] += res;
      break;
    }
  }
  for (auto i : ans) {
    cout << i << "\n";
  }
}