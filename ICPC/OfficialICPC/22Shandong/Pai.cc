#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5;
int n, k;
string s, ans;
int dfs(int i) {
  if (i >= N) {
    int cnt = 0;
    for (int j = 1; j < N; ++j) {
      if (ans[j] != ans[j - 1])
        cnt++;
    }
    if (cnt == k) {
      return 1;
    } else {
      return 0;
    }
  }
  if (s[i] != '?') {
    ans[i] = s[i];
    return dfs(i + 1);
  }
  for (char j = '0'; j <= '1'; ++j) {
    ans[i] = j;
    if (dfs(i + 1))
      return 1;
  }
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    assert(n == N);
    cin >> s;
    ans = s;
    if (dfs(0)) {
      cout << ans << "\n";
    } else {
      cout << "Impossible\n";
    }
  }
}