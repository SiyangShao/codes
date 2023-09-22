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
constexpr int N = 400;
array<ll, N> two, inv2;
void init() {
  two[0] = 1;
  for (int i = 1; i < N; ++i) {
    two[i] = 2 * two[i - 1] % MOD;
  }
  inv2[N - 1] = qpow(two[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) {
    inv2[i] = inv2[i + 1] * 2 % MOD;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edg(m);
  for (auto &[u, v] : edg) {
    cin >> u >> v;
    u--, v--;
  }
  ll ans = 0;
  for (ll i = 0; i < (1LL << n); ++i) {
    ll num = 0;
    for (auto &[u, v] : edg) {
      if (((i >> u) & 1) != ((i >> v) & 1)) {
        num++;
      }
    }
    cout << i << " " << num << "\n";
    ans = (ans + inv2[num]) % MOD;
  }
  ans = ans * qpow((1LL << n), MOD - 2) % MOD;
  cout << ans << "\n";
}