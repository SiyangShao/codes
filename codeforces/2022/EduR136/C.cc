#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr ll N = 65;
array<array<ll, N>, N> C;
array<pair<ll, ll>, N> ans;
auto init() {
  C[1][0] = C[1][1] = 1;
  for (ll i = 2; i < N; ++i) {
    C[i][0] = 1;
    for (ll j = 1; j < N; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  ans[2] = {1, 0};
  for (ll i = 4; i <= 60; ++i) {
    ans[i].first = C[i - 1][(i / 2) - 1];
    ans[i].first += ans[i - 2].second;
    ans[i].first %= MOD;
    ll all = C[i][i / 2];
    all = (all + MOD - 1) % MOD;
    ans[i].second = (all + MOD - ans[i].first) % MOD;
  }
}
auto solve() {
  ll n;
  cin >> n;
  cout << ans[n].first << " " << ans[n].second << " 1\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  cin >> _;
  while (_--) {
    solve();
  }
}