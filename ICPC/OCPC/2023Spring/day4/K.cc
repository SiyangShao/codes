#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
pair<ll, ll> fib(ll n) {
  if (n == 0)
    return {0, 1};
  auto p = fib(n >> 1);
  ll c = p.first * ((2 * p.second % MOD - p.first + MOD) % MOD) % MOD;
  ll d = p.first * p.first % MOD + p.second * p.second % MOD;
  d %= MOD;
  if (n & 1)
    return {d, (c + d) % MOD};
  else
    return {c, d};
}

auto solve() {
  ll n;
  cin >> n;
  if (n % 4 != 0 && n % 4 != 1) {
    cout << "0\n";
    return;
  }
  if (n % 4 == 0) {
    n -= 3;
  }
  ll cnt = n / 4;
  cnt += 2;
  auto [x, y] = fib(cnt);
  cout << x << "\n";
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