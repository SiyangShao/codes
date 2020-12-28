#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 700;
array<array<ll, N>, N> C, pre;
void init() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = pre[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      C[i][j] %= MOD;
      pre[i][j] = (pre[i - 1][j] + 2 * pre[i - 1][j - 1] * j) % MOD;
      if (j >= 2) {
        pre[i][j] += pre[i - 1][j - 2] * j % MOD * (j - 1) % MOD;
        pre[i][j] %= MOD;
      }
    }
  }
}
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  ll n;
  cin >> n;
  vector<int> is_key(n * 2 + 1, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    is_key[a] = 1;
  }
  vector dp(n * 2 + 2, vector<ll>(n * 2 + 1, 0));
  dp[n * 2 + 1][0] = 1;
  ll key = 0, cnt = 0;
  for (ll i = n * 2; i >= 1; --i) {
    if (is_key[i]) {
      for (ll j = 0; j <= key + 1; ++j) {
        dp[i][j] = dp[i + 1][j];
        for (ll k = 1; k <= j; ++k) {
          dp[i][j] += dp[i + 1][j - k] * C[key - (j - k)][k - 1] % MOD *
                      pre[k - 1][k - 1] % MOD * (k + 1) % MOD;
          dp[i][j] %= MOD;
        }
      }
      key++;
    } else {
      for (ll j = 0; j <= key; ++j) {
        dp[i][j] = dp[i + 1][j] * (j * 2 - (j + cnt)) % MOD;
      }
      cnt++;
    }
  }
  ll ans = dp[1][n];
  ans *= qpow(qpow(2, n), MOD - 2);
  ans %= MOD;
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