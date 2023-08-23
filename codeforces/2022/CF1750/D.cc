#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
map<ll, vector<ll>> pri;
auto cal(ll m, ll n) {
  vector<ll> p;
  ll t = m;
  if (pri.contains(m)) {
    p = pri[m];
  } else {
    for (ll i = 2; i * i <= m; ++i) {
      if (m % i == 0) {
        p.emplace_back(i);
        while (m % i == 0)
          m /= i;
      }
    }
    if (m > 1) {
      p.emplace_back(m);
    }
    pri[t] = p;
  }
  ll sz = (ll)p.size(), sum = 0;
  for (ll i = 1; i < (1LL << sz); ++i) {
    ll ct = 0;
    ll mul = 1;
    for (ll j = 0; j < sz; ++j) {
      if (i & (1LL << j)) {
        ct++;
        mul *= p[j];
      }
    }
    if (ct & 1) {
      sum += n / mul;
    } else {
      sum -= n / mul;
    }
  }
  return n - sum;
}
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll ans = 1;
  for (ll i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      ans = ans * (m / a[i]) % MOD;
    } else if (a[i - 1] % a[i] != 0) {
      ans = 0;
      break;
    } else {
      ans = ans * cal(a[i - 1] / a[i], m / a[i]) % MOD;
    }
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