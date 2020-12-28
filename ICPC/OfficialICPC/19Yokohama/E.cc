#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &e : a)
    cin >> e;

  vector<vector<ll>> g(n);
  for (ll i = 0; i < n; ++i)
    for (ll j = i + 1; j < n; ++j)
      if (a[i] > a[j])
        g[i].emplace_back(j), g[j].emplace_back(i);

  vector<ll> color(n, -1);
  bool gg = false;
  ll cnt[2] = {0, 0};
  function<void(ll, bool)> dfs = [&](ll o, bool clr) {
    color[o] = clr;
    cnt[clr]++;
    for (auto e : g[o]) {
      if (color[e] != -1) {
        if (color[e] != !clr)
          gg = true;
      } else {
        dfs(e, !clr);
      }
    }
  };
  vector<pair<ll, ll>> decision;
  for (ll i = 0; i < n; ++i)
    if (color[i] == -1) {
      cnt[0] = cnt[1] = 0;
      dfs(i, false);
      decision.emplace_back(cnt[0], cnt[1]);
    }

  // putting m - base into
  if (gg)
    cout << 0 << "\n";
  else {
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    constexpr ll MOD = 1e9 + 7;
    for (auto [l, r] : decision) {
      if (l > r)
        swap(l, r);
      // cout << l << " " << r << "\n";
      vector<ll> nxt(n + 1, 0);
      for (int i = 0; i <= n; ++i) {
        if (i < l)
          continue;
        if (i < r) {
          nxt[i] = dp[i - l];
        } else {
          nxt[i] = dp[i - l] + dp[i - r];
          if (nxt[i] >= MOD)
            nxt[i] -= MOD;
        }
      }
      dp = nxt;
    }
    ll sum = 0;
    for (ll i = min(m, n - m); i <= max(m, n - m); ++i) {
      sum += dp[i];
      if (sum > MOD) {
        sum -= MOD;
      }
    }
    cout << sum << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  ll T = 1;
  // cin >> T;
  while (T--)
    solve();
  return 0;
}