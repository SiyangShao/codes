#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll euler_phi(ll n) {
  ll ans = n;
  for (ll i = 2; i * i <= n; i++)
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0)
        n /= i;
    }
  if (n > 1)
    ans = ans / n * (n - 1);
  return ans;
}
auto solve() {
  ll a, m;
  cin >> a >> m;
  ll x = gcd(a, m);
  m /= x;
  cout << euler_phi(m) << "\n";
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