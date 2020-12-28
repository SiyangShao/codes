#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e9;
constexpr ll N = 1e5 + 7, kk = 101;
array<array<ll, kk>, N> dp;
vector<vector<int>> E;
using edge = tuple<int, int, ll>;
vector<edge> edg, new_edg;
vector<ll> all_w;
void reassign(ll x) {
  for (int i = 0; auto &[u, v, w] : new_edg) {
    if (get<2>(edg[i]) >= x) {
      w = 1;
    } else {
      w = -1;
    }
    i++;
  }
}
bool check(ll x, ll k, ll n) {
  x = all_w[x];
  reassign(x);
  for (int len = 1; len <= k * 2; len++) {
    for (int u = 0; u < n; ++u) {
      dp[u][len] = -inf;
      for (auto id : E[u]) {
        auto [_, v, w] = new_edg[id];
        dp[u][len] = max(dp[u][len], dp[v][len - 1] + w);
      }
      if (len >= k && dp[u][len] > 0) {
        return true;
      }
    }
  }
  return false;
}
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  E.resize(n);
  edg.resize(m);
  for (int i = 0; auto &[u, v, w] : edg) {
    cin >> u >> v >> w;
    u--, v--;
    all_w.emplace_back(w);
    E[u].emplace_back(i);
    i++;
  }
  new_edg = edg;
  for (int i = 0; i < n; ++i) {
    dp[i][0] = 0;
  }
  sort(all_w.begin(), all_w.end());
  all_w.erase(unique(all_w.begin(), all_w.end()), all_w.end());
  ll l = 0, r = (ll)all_w.size() - 1;
  ll ans = l;
  if (!check(l, k, n)) {
    cout << "-1\n";
    return;
  }
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (check(mid, k, n)) {
      l = mid + 1;
      ans = max(ans, mid);
    } else {
      r = mid - 1;
    }
  }
  cout << all_w[ans] << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}