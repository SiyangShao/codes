#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 9;
constexpr ll MAXN = 1LL << 20;
array<ll, MAXN> a;
ll cal(ll l, ll r) {
  if (r == l + 1) {
    return (a[l] * a[r] % MOD - a[r] * a[r] % MOD + MOD) % MOD;
  }
  ll len = r - l + 1;
  len /= 2;
  for (ll i = 0; i < len; ++i) {
    a[i + l] -= a[i + l + len];
    a[i + l] = (a[i + l] + MOD) % MOD;
  }
  ll x = cal(l, l + len - 1) % MOD;
  ll y = cal(l + len, r) % MOD;
  // cout << l << " " << l + len - 1 << " " << x << ", " << l + len << " " << r
  //  << " " << y << "\n";
  return (x * y) % MOD;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (1 << n); ++i) {
    cin >> a[i];
  }
  cout << cal(0, (1 << n) - 1) << "\n";
}