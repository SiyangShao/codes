#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 85;
array<ll, N> f;
array<array<pair<ll, pair<ll, ll>>, 100>, N> cache;
array<int, N> cnt;
pair<ll, ll> cal(ll x, int n) {
  for (int i = 0; i < cnt[n]; i++) {
    if (cache[n][i].first == x)
      return cache[n][i].second;
  }
  if (n == 0)
    return {0, 0};
  if (n == 1)
    return {x == 1 ? 0 : 1, x == 1 ? 1 : 0};
  if (x > f[n - 1]) {
    auto t = cal(x - f[n - 1], n - 2);
    pair<ll, ll> ans = {t.first + 1, t.second};
    cache[n][cnt[n]++] = {x, ans};
    return ans;
  } else {
    auto t = cal(x, n - 1);
    pair<ll, ll> ans = {min(t.first, t.second + 2),
                        min(t.first, t.second) + 1 + (n - 1) / 2};
    cache[n][cnt[n]++] = {x, ans};
    return ans;
  }
}
ll sol(ll a, ll b, int n) {
  if (a > b)
    swap(a, b);
  if (a == b)
    return 0;
  if (n == 0)
    return 0;
  if (n == 1)
    return (a == b ? 0 : 1);
  if (b == a + 1)
    return 1;
  if (a <= f[n - 1] && b >= f[n - 1] + 1) {
    auto toa = cal(a, n - 1);
    auto tob = cal(b - f[n - 1], n - 2);
    return min(toa.first, toa.second) + tob.first + 1;
  } else if (a >= f[n - 1] + 1 && b >= f[n - 1] + 1) {
    return sol(a - f[n - 1], b - f[n - 1], n - 2);
  } else {
    assert(a <= f[n - 1] && b <= f[n - 1]);
    auto toa = cal(a, n - 1), tob = cal(b, n - 1);
    return min(sol(a, b, n - 1),
               min(toa.first, toa.second) + min(tob.first, tob.second) + 2);
  }
}
auto solve() {
  int t, n;
  cin >> t >> n;
  n = min(n, 80);
  f[0] = 1, f[1] = 2;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  while (t--) {
    ll l, r;
    cin >> l >> r;
    for (int i = 0; i <= n; i++) {
      cnt[i] = 0;
    }
    cout << sol(l, r, n) << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solve();
}
