#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n;
  cin >> n;
  ll a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  ll ans = 1e16;
  for (int dif = 0; dif < n; ++dif) {
    // i->i-dif
    ll cnt = dif * a;
    for (int i = 0; i < n / 2; ++i) {
      if (s[(i + dif) % n] == s[(n - 1 - i + dif) % n]) {
        continue;
      } else {
        cnt += b;
      }
    }
    ans = min(ans, cnt);
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}