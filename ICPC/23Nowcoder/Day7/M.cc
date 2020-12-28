#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  ll cur = 1, cnt = 1;
  ll ans = 0;
  while (cur <= n) {
    ll num = min(cur * 10 - 1, n) - cur + 1;
    ans += num * cnt;
    cur *= 10;
    cnt++;
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