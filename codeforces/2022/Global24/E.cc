#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> p(n);
  for (auto &[a, b] : p) {
    cin >> a >> b;
  }
  if (p[0].first >= k) {
    cout << "YES\n";
    return;
  }
  if (n == 1) {
    cout << "NO\n";
    return;
  }
  if (p[0].first + p[0].second < k) {
    cout << "NO\n";
    return;
  }
  k -= p[0].second;
  sort(p.begin() + 1, p.end(), [](auto x, auto y) {
    if (x.first != y.first) {
      return x.first < y.first;
    } else {
      return x.second > y.second;
    }
  });
  array dp = {(ll)-1e16, (ll)-1e16};
  for (int i = 1; i < n; ++i) {
    auto nxt = dp;
    nxt[1] = max(nxt[1], dp[0]);
    nxt[0] = max(nxt[0], p[i].first + p[i].second);
    nxt[1] = max(nxt[1], p[i].first);
    nxt[0] = max(nxt[0], min(dp[0], p[i].first) + p[i].second);
    nxt[1] = max(nxt[1], min(dp[1], p[i].first) + p[i].second);
    dp = nxt;
    if (dp[1] >= k) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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