#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
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
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<ll> siz(n), val(n), sum(n), dsiz(n);
  ll ans = 0;
  function<void(int, int)> dfs = [&](int u, int fa) {
    siz[u] = 1;
    ll cnt = 0;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      siz[u] += siz[v];
      dsiz[u] = (dsiz[u] + dsiz[v]) % MOD;
      val[u] += val[v] + 2 * sum[v] + siz[v];
      sum[u] += sum[v];
    }
    dsiz[u] += siz[u];
    sum[u] += dsiz[u];
    val[u] += (siz[u] - 1) * 2 + 1;
    cout << u + 1 << " " << val[u] << " " << sum[u] << " " << dsiz[u] << "\n";
    ll sum = 0;
    ll choose = 0;
    // Case 1: one is after and another is not
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      choose++;
      ll res = (n - siz[v]) * 2 - 1;
      cnt = (cnt + val[v] * res) % MOD;
      sum = (sum + val[v]) % MOD;
    }
    cout << u + 1 << " " << cnt << "\n";
    // Case 2: both are in the subtree
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      ll res = (sum - val[v] + MOD) % MOD;
      cnt = (cnt + val[v] * res) % MOD;
      cnt = (cnt + val[v] * (choose - 1)) % MOD;
    }
    ans = (ans + cnt) % MOD;
    cout << u + 1 << " " << cnt << "\n";
  };
  dfs(0, 0);
  cout << ans << "\n";
  ll method = n * (n - 1) / 2;
  method %= MOD;
  method = method * method % MOD;
  method = qpow(method, MOD - 2);
  cout << ans * method % MOD << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
