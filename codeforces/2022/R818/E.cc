#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * @brief
 * sum{lcm(c, gcd(a,b))} which a + b + c = n.
 * Consider each possible c. (a+b) % gcd(a,b) == 0
 * @return auto
 */
constexpr ll N = 1e5 + 7;
bitset<N> is_prime;
vector<ll> prime;
array<ll, N> phi;
constexpr ll MOD = 1e9 + 7;
auto init() {
  is_prime.flip();
  is_prime[1] = false, phi[1] = 1;
  for (ll i = 2; i < N; ++i) {
    if (is_prime[i]) {
      prime.emplace_back(i);
      phi[i] = i - 1;
    }
    for (auto j : prime) {
      if (i * j >= N)
        break;
      is_prime[i * j] = false;
      if (i % j) {
        phi[i * j] = phi[i] * phi[j];
      } else {
        phi[i * j] = phi[i] * j;
        break;
      }
    }
  }
}
auto solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  auto cal = [&](ll c, ll d) {
    assert((n - c) % d == 0);
    return (ll)lcm(c, d) * (ll)phi[(n - c) / d] % MOD;
    ans %= MOD;
  };
  for (ll c = 1; c + 2 <= n; ++c) {
    ll sum = n - c;
    ll mid = sqrt(sum);
    for (ll i = 1; i <= mid; ++i) {
      if (sum % i == 0) {
        ans = (ans + cal(c, i)) % MOD;
        if (i != 1 && i != sum / i)
          ans = (ans + cal(c, sum / i)) % MOD;
      }
    }
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  // cin >> _;
  while (_--) {
    solve();
  }
}