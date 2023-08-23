#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll cal(ll b, ll c, ll k, ll n) {
  // k * a + b = c
  c -= b;
  if (c % k != 0)
    return 0;
  ll a = c / k;
  if (a == 0)
    return 0;
  if (gcd(a, b) >= n)
    return 1;
  return 0;
}
auto solve() {
  ll k, c, n;
  cin >> k >> c >> n;
  ll ans = 0;
  for (ll i = 1; i * i <= c; ++i) {
    if (c % i != 0)
      continue;
    ans += cal(i, c, k, n);
    if (c / i != i) {
      ans += cal(c / i, c, k, n);
    }
  }
  cout << ans << "\n";
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