#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
pair<ll, ll> fib(ll n) {
  if (n == 0)
    return {0, 1};
  auto p = fib(n >> 1);
  ll c = p.first * ((2 * p.second % MOD + MOD - p.first) % MOD);
  c %= MOD;
  ll d = p.first * p.first % MOD + p.second * p.second % MOD;
  d %= MOD;
  if (n & 1)
    return {d, (c + d) % MOD};
  else
    return {c, d};
}
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> rock(m + 2);
  rock[0] = -1;
  rock[m + 1] = n + 1;
  for (ll i = 1; i <= m; ++i) {
    cin >> rock[i];
  }
  sort(rock.begin(), rock.end());
  ll ans = 1;
  for (ll i = 1; i <= m + 1; ++i) {
    auto dif = rock[i] - rock[i - 1] - 1;
    ans = ans * fib(dif).first % MOD;
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin>>_;
  while (_--) {
    solve();
  }
}
