#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 0;
  for (ll i = 1; i < n * 2; ++i) {
    if (s[i] == '(' && s[i - 1] == '(') {
      ans++;
    }
  }
  cout << ans + 1 << "\n";
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