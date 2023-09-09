#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool is_prime(ll x) {
  for (ll i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
auto solve() {
  ll x;
  cin >> x;
  vector<ll> ans;
  while (popcount((unsigned long long)x) != 1) {
    ans.emplace_back(x);
    ll lsb = x & -x;
    x -= lsb;
  }
  while (x != 1) {
    ans.emplace_back(x);
    x /= 2;
  }
  ans.emplace_back(x);
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
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