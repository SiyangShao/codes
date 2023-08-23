#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e18 + 7;
bool check(ll x, ll n, ll y) {
  while (n) {
    n--;
    y /= x;
  }
  return y >= 1;
}
ll revpow(ll n, ll y) {
  ll l = 1, r = N, ans = 1;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (check(mid, n, y)) {
      l = mid + 1;
      ans = max(ans, mid);
    } else {
      r = mid - 1;
    }
  }
  return ans;
}