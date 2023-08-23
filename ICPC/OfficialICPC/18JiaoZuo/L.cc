#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll inv(ll x) {
  ll res = 1;
  ll y = MOD - 2;
  while (y) {
    if (y & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
constexpr ll inv4 = inv(4LL * 3LL * 2LL);
constexpr ll inv2 = inv(2LL);
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  vector<int> deg(n);
  set<pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
    deg[u]++, deg[v]++;
  }
  function<ll(ll)> C4 = [&](ll u) {
    return u * (u - 1) % MOD * (u - 2) % MOD * (u - 3) % MOD * inv4 % MOD;
  };
  vector<int> id(n), pos(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int x, int y) { return deg[x] < deg[y]; });
  for (int i = 0; i < n; ++i) {
    pos[id[i]] = i;
  }
  vector<vector<int>> G(n);
  for (int i = 0; i < n; ++i) {
    for (auto j : E[i]) {
      if (pos[i] < pos[j]) {
        G[i].emplace_back(j);
      }
    }
  }
  function<ll()> solve_line = [&]() {
    // line + 5 * triangle + 4 * square
    ll ans = 0;
    for (int u = 0; u < n; ++u) {
      ll sum = 0;
      for (auto v : E[u]) {
        ll coef = deg[v] - 1;
        ans = ans + (sum * coef) % MOD;
        if (ans >= MOD)
          ans -= MOD;
        sum = sum + coef;
        if (sum >= MOD)
          sum -= MOD;
      }
    }
    return ans;
  };
  function<ll()> solve_line_dev = [&]() {
    // line with div + triangle * 2
    ll ans = 0;
    for (int u = 0; u < n; ++u) {
      if (deg[u] <= 2)
        continue;
      ll ways = inv2 * ((ll)(deg[u] - 1)) % MOD * (ll)(deg[u] - 2) % MOD;
      for (auto v : E[u]) {
        ans = ans + (ll)(deg[v] - 1) * ways % MOD;
        if (ans >= MOD)
          ans -= MOD;
      }
    }
    return ans;
  };
  function<ll()> solve_flower = [&]() {
    // flower
    ll ans = 0;
    for (int u = 0; u < n; ++u) {
      if (deg[u] < 4)
        continue;
      ll cnt = inv4;
      for (int i = 0; i < 4; ++i) {
        cnt = cnt * ((ll)deg[u] - i);
        cnt %= MOD;
      }
      ans = (ans + cnt) % MOD;
    }
    return ans;
  };
  function<ll()> solve_triangle = [&]() {
    // triangle * 2
    ll ans = 0;
    vector<int> connect(n, 0);
    for (int u = 0; u < n; ++u) {
      for (auto v : G[u]) {
        connect[v] = 1;
      }
      for (auto v : G[u]) {
        for (auto w : G[v]) {
          if (connect[w]) {
            ans = ans + (deg[u] + deg[v] + deg[w] - 5);
            if (ans >= MOD) {
              ans -= MOD;
            }
          }
        }
      }
      for (auto v : G[u]) {
        connect[v] = 0;
      }
    }
    return ans;
  };
  function<ll()> solve_square = [&]() {
    ll ans = 0;
    vector<ll> cnt(n);
    for (int u = 0; u < n; ++u) {
      for (auto v : E[u]) {
        for (auto w : G[v]) {
          if (pos[w] > pos[u]) {
            ans = (ans + cnt[w] >= MOD ? ans + cnt[w] - MOD : ans + cnt[w]);
            cnt[w]++;
          }
        }
      }
      for (auto v : E[u]) {
        for (auto w : G[v]) {
          if (pos[w] > pos[u]) {
            cnt[w] = 0;
          }
        }
      }
    }
    return ans;
  };
  ll ans = solve_line();
  ans = (ans + solve_line_dev()) % MOD;
  ans = (ans + solve_flower()) % MOD;
  ans = (ans + MOD - (3 * solve_triangle()) % MOD) % MOD;
  ans = (ans + MOD - (3 * solve_square()) % MOD) % MOD;
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