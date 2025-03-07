#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  array<int, 26> c;
  fill(c.begin(), c.end(), 0);
  for (auto i : s) {
    c[i - 'a']++;
  }
  for (auto i : t) {
    c[i - 'a']--;
  }
  for (auto i : c) {
    if (i != 0) {
      cout << "-1\n";
      return;
    }
  }
  s = "_" + s;
  t = "_" + t;
  vector prefs(26, vector<int>(n + 1)), preft(26, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    prefs[s[i] - 'a'][i]++;
    preft[t[i] - 'a'][i]++;
    for (int j = 0; j < 26; j++) {
      prefs[j][i] += prefs[j][i - 1];
      preft[j][i] += preft[j][i - 1];
    }
  }
  vector dp(n + 1, vector<int>(n + 1, -1));
  for (int i = 0; i <= n; i++) {
    dp[0][i] = 0;
  }
  // dp[i-j]: min cost to transfer s[1..i] to t[1..j]
  auto dfs = [&](auto self, int i, int j) -> int {
    int &ans = dp[i][j];
    if (ans != -1)
      return ans;
    ans = 1e9;
    if (i > 0) {
      ans = 1 + self(self, i - 1, j);
      if (s[i] == t[j]) {
        ans = min(ans, self(self, i - 1, j - 1));
      }
    }
    int ch = t[j] - 'a';
    if (prefs[ch][n] - prefs[ch][i] > preft[ch][n] - preft[ch][j]) {
      ans = min(ans, self(self, i, j - 1));
    }
    return ans;
  };
  dfs(dfs, n, n);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
  cout << dp[n][n] << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
