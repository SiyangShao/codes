#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class ExtendedGCD {
public:
  ll gcd, x, y;
  ExtendedGCD(ll _gcd, ll _x, ll _y) : gcd(_gcd), x(_x), y(_y) {}
};
ExtendedGCD extendedGCD(ll a, ll b) {
  if (b == 0) {
    return {a, 1, 0};
  } else {
    ExtendedGCD e = extendedGCD(b, a % b);
    ll x = e.y;
    ll y = e.x - (a / b) * e.y;
    return {e.gcd, x, y};
  }
}
pair<ll, ll> exgcd(ll a, ll b, ll c) {
  ExtendedGCD e = extendedGCD(a, b);
  if (c % e.gcd != 0) {
    return {-1, -1};
  }
  ll x = e.x * (c / e.gcd);
  ll y = e.y * (c / e.gcd);
  return {x, y};
}
constexpr ll inf = 1e16;
auto solve() {
  ll A, B, C;
  cin >> A >> B >> C;

  ll g = gcd(A, B);
  if (C % g != 0) {
    cout << "-1\n";
    return;
  }
  auto [x, y] = exgcd(A, B, C);
  A /= g, B /= g;
  // cout << x << " " << y << "\n";
  auto sol = [&](ll t, ll X, ll Y) {
    ll r = X + B * t, s = Y - A * t;
    return max(2 * (r + s), 2 * (abs(r) + abs(s)) - 1);
  };
  ll ans = inf;
  for (ll i = -x / B - 1; i <= -x / B + 1; ++i) {
    ans = min(ans, sol(i, x, y));
  }
  for (ll i = y / A - 1; i <= y / A + 1; ++i) {
    ans = min(ans, sol(i, x, y));
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