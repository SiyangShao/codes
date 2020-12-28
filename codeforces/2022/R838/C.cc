#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 1, cur = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      cur *= 2;
      cur %= MOD;
    } else {
      cur = 1;
    }
    ans += cur;
    ans %= MOD;
  }
  cout << ans << "\n";
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
