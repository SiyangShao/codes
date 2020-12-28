#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  ll n, k, lmd;
  cin >> n >> k >> lmd;
  if (lmd == 0 || lmd == 1) {
    cout << "0\n";
    return;
  }
  // loop
  ll base = qpow(lmd - 1, k) + (k % 2 == 0 ? 1 : -1) * (lmd - 1);
  base = (base % MOD + MOD) % MOD;
  // cycle
  ll bb = qpow(lmd - 1, 4) + (lmd - 1);
  bb %= MOD;
  bb *= qpow(lmd * (lmd - 1) % MOD, MOD - 2);
  bb %= MOD;
  bb = qpow(bb, n - 1);
  bb %= MOD;
  bb = qpow(bb, k);
  bb %= MOD;
  ll ans = base * bb;
  ans = (ans % MOD + MOD) % MOD;
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