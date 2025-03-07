#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (n < 7) {
    cout << "0\n";
    return;
  }
  s += s;
  if (k > 7) {
    k = 7;
  }
  int ans = 0;
  for (int j = 0; j <= k; j++) {
    int cnt = 0;
    for (int i = j; i <= j + n - 7; i++) {
      cnt += (s.substr(i, 7) == "nanjing");
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
