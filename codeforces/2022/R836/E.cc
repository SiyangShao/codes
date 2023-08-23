#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
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
  ll n, m, h;
  cin >> n >> m >> h;
  vector mp(n, vector<ll>(m));
  for (auto &i : mp) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  vector<vector<pair<int, ll>>> E(n + m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (~mp[i][j]) {
        E[i].emplace_back(j + n, -mp[i][j] - 1);
        E[j + n].emplace_back(i, -mp[i][j] - 1);
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    int p = -1;
    for (int i = 0; i < n; ++i) {
      if (~mp[i][j])
        p = i;
    }
    if (~p) {
      for (int i = 0; i < p; ++i) {
        if (~mp[i][j]) {
          E[p].emplace_back(i, (mp[i][j] - mp[p][j] + h) % h);
          E[i].emplace_back(p, (mp[p][j] - mp[i][j] + h) % h);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int p = -1;
    for (int j = 0; j < m; ++j) {
      if (~mp[i][j])
        p = j;
    }
    if (~p) {
      for (int j = 0; j < p; ++j) {
        if (~mp[i][j]) {
          E[p + n].emplace_back(j + n, (mp[i][j] - mp[i][p] + h) % h);
          E[j + n].emplace_back(p + n, (mp[i][p] - mp[i][j] + h) % h);
        }
      }
    }
  }
  vector<ll> val(n + m, -1);
  function<bool(int, ll)> dfs = [&](int u, int k) {
    if (~val[u]) {
      return val[u] == k;
    }
    val[u] = k;
    for (auto [v, w] : E[u]) {
      auto nxt = w < 0 ? (-w - 1 - k + h) % h : (k + w) % h;
      // u + v == w (mp[u][v] = w)
      // u - v == w (mp[u][k] - mp[v][k] == w)
      if (!dfs(v, nxt))
        return false;
    }
    return true;
  };
  ll res = 0;
  for (int i = 0; i < n + m; ++i) {
    if (val[i] == -1) {
      res++;
      if (!dfs(i, 0)) {
        cout << "0\n";
        return;
      }
    }
  }
  cout << qpow(h, res - 1) << "\n";
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