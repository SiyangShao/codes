#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr ll INF = 1e9 + 7;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  ll n;
  cin >> n;
  vector<ll> op(n), x(n);
  ll sum = 0;
  for (ll i = 0; i < n; ++i) {
    cin >> op[i];
    switch (op[i]) {
    case 1:
      cin >> x[i];
      break;
    case 2:
      cin >> x[i];
      sum += x[i];
      sum = min(sum, INF);
      break;
    case 3:
      x[i] = sum;
      sum *= 2;
      sum = min(sum, INF);
      break;
    default:
      assert(false);
    }
  }
  ll sub = 0, zero = 1, ans = 0;
  vector<ll> v;
  for (ll i = n - 1; i >= 0; --i) {
    if (op[i] == 2) {
      sub += x[i];
    } else if (op[i] == 3) {
      if (x[i] == INF)
        continue;
      else if (x[i] == 0)
        zero = (zero * 2) % MOD;
      else
        v.emplace_back(x[i]);
    } else {
      if (x[i] <= sub)
        continue;
      x[i] -= sub;
      ll t = 1, sz = (ll)v.size();
      for (ll j = 0; j < sz; ++j) {
        if (x[i] > v[j]) {
          t = (t + qpow(2, sz - 1 - j)) % MOD;
          x[i] -= v[j];
        }
      }
      ans = (ans + (t * zero) % MOD) % MOD;
    }
  }
  cout << ans;
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