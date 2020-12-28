#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> b(n), w(n), dif(n);
  for (auto &i : b) {
    cin >> i;
  }
  for (auto &i : w) {
    cin >> i;
  }
  for (ll i = 0; i < n; ++i) {
    dif[i] = w[i] - b[i];
  }
  vector<vector<ll>> E(n);
  for (ll i = 1; i < n; ++i) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector dp(n, vector<pair<ll, ll>>());
  vector<ll> siz(n, 0);
  function<void(ll, ll)> merge = [&](ll u, ll v) {
    vector ndp(dp[u].size() + dp[v].size(), pii{-1, 0});
    for (ll i = 0; i < dp[u].size(); ++i) {
      for (ll j = 0; j < dp[v].size(); ++j) {
        ndp[i + j] = max(ndp[i + j], {dp[u][i].first + dp[v][j].first,
                                      dp[u][i].second + dp[v][j].second});
        // if (i + j + 1 < dp[u].size() + dp[v].size())
        ndp[i + j + 1] = max(ndp[i + j + 1], {dp[u][i].first + dp[v][j].first +
                                                  (dp[v][j].second > 0 ? 1 : 0),
                                              dp[u][i].second});
      }
    }
    dp[u] = move(ndp);
  };
  function<void(ll, ll)> dfs = [&](ll u, ll fa) {
    dp[u].emplace_back(0, dif[u]);
    // cout << u + 1 << ":\n";
    // for (ll i = 1; i <= min(siz[u], m); ++i) {
    //   cout << dp[u][i].first << ", " << dp[u][i].second << "\n";
    // }
    // cout << "\n";
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      merge(u, v);
    }
    // cout << u + 1 << ":\n";
    // for (ll i = 0; i < dp[u].size(); ++i) {
    //   cout << dp[u][i].first << ", " << dp[u][i].second << "\n";
    // }
    // cout << "\n";
  };
  dfs(0, 0);
  cout << dp[0][m - 1].first + (dp[0][m - 1].second > 0 ? 1 : 0) << "\n";
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