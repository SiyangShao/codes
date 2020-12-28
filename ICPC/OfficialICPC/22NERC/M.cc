#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<tuple<ll, ll, ll>> vec;
  function<void(ll)> add = [&](ll i) {
    ll x = n / i;
    // x + y = x
    if (x < 2)
      return;
    vec.emplace_back(i * (x - 1), i, i * (x - 1));
  };
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i != 0)
      continue;
    // suppose i is the gcd of a and b
    // a = i * x, b = i * y
    // lcm(a, b) = x * y * i
    // x + y = n / i
    add(i);
    if (n / i != i) {
      add(n / i);
    }
  }
  auto [_, x, y] = *min_element(vec.begin(), vec.end());
  cout << x << " " << y << "\n";
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