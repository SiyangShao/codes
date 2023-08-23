#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
auto solve() {
  ll x;
  cin >> x;
  string s;
  cin >> s;
  ll n = (ll)s.length();
  s = "_" + s;
  vector<ll> num(n + 1, 0);
  for (ll i = 1; i <= n; ++i) {
    num[i] = s[i] - '0';
  }
  for (ll i = 1; i <= x; ++i) {
    if (num.size() <= x) {
      ll cur = num.size();
      for (ll j = 1; j < num[i]; ++j) {
        for (ll k = i + 1; k < cur; ++k) {
          num.emplace_back(num[k]);
        }
      }
    }
    ll res = (n + MOD - i) % MOD;
    n = n + (num[i] - 1) * res % MOD;
    n %= MOD;
  }
  cout << n << "\n";
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