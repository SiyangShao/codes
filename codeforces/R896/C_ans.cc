#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

ll tot[505], n, m, dp[125][125], dp2[125], g[125][125], g2[125], f[125],
    pw[100005][125];
const ll mod = 998244353;

inline ll dep(ll root) {
  if (root > n)
    return 0;
  return dep(root * 2) + 1;
}

inline ll dep2(ll root) {
  if (root > n)
    return 0;
  return dep2(root * 2 + 1) + 1;
}

inline bool full(ll root) { return dep(root) == dep2(root); }

void dfs(ll root) {
  if (root * 2 > n) {
    g2[0] = dp2[0] = 1;
    return;
  }
  if (root * 2 == n) {
    g2[0] = 2, g2[1] = 1;
    dp2[0] = 1, dp2[1] = 1;
    return;
  }
  ll d = 0;
  if (full(root * 2)) {

    d = dep(root * 2);
    dfs(root * 2 + 1);
  } else {
    d = dep(root * 2 + 1);
    dfs(root * 2);
  }
  ll mx = 2 * d + 4;
  for (ll i = 0; i <= mx; i++) {
    g2[i] += g[d][i];
    for (ll j = 0; j <= min(d + 2, i); j++) {
      g2[i + 2] += dp2[j] * dp[d][i - j] % mod;
    }
  }
  for (ll i = mx; i > 0; i--)
    dp2[i] = (dp2[i - 1] + dp[d][i - 1]) % mod;
  dp2[0] = 1;
  for (ll i = 0; i <= mx; i++)
    g2[i] += dp2[i], g2[i] %= mod;
}

inline ll qkp(ll a, ll k) {
  ll ans = 1;
  while (k) {
    if (k & 1)
      ans *= a, ans %= mod;
    a *= a, a %= mod;
    k >>= 1;
  }
  return ans;
}

int main() {
  ll t;
  scanf("%lld", &t);
  for (ll i = 1; i <= 60; i++) {
    dp[i][0] = 1;
    for (ll j = 1; j <= i - 1; j++) {
      dp[i][j] = 2 * dp[i - 1][j - 1] % mod;
    }
    for (ll j = 0; j <= 2 * i - 2; j++) {
      g[i][j] += g[i - 1][j] * 2;
      g[i][j] += dp[i][j];
      g[i][j] %= mod;
      for (ll k = 0; k <= j; k++) {
        g[i][j + 2] += dp[i - 1][k] * dp[i - 1][j - k] % mod;
        g[i][j + 2] %= mod;
      }
    }
  }
  while (t--) {
    scanf("%lld%lld", &n, &m);

    // log n^3
    dfs(1);
    ll d = dep(1), ans = 0;
    printf("%lld ", d);
    for (ll j = 0; j <= m; j++) {
      pw[j][0] = 1;
      for (ll i = 1; i <= 2 * d; i++) {
        pw[j][i] = pw[j][i - 1] * j % mod;
      }
    }

    for (ll i = 0; i <= 2 * d - 2; i++) {
      for (ll j = 1; j <= m; j++) {
        f[i] += (pw[j][i + 2] + mod - pw[j - 1][i + 1] * j % mod) % mod;
        f[i] %= mod;
      }
      if (n >= i + 1)
        ans += f[i] * g2[i] % mod * qkp(m, n - i - 1) % mod;
      ans %= mod;
    }
    printf("%lld\n", ans);
    for (ll i = 1; i <= 60; i++) {
      for (ll j = 0; j <= 2 * i - 2; j++) {
        f[j] = g2[j] = dp2[j] = 0;
      }
    }
  }

  return 0;
}