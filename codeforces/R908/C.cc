#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int m;
  cin >> m;
  vector<int> n(m);
  vector<ll> l(m), r(m), sum(m);
  vector a(m, vector<ll>());
  vector c(m, vector<ll>());
  ll L = 0, R = 0, N = 0;
  map<ll, vector<pair<int, ll>>> mp;
  for (int i = 0; i < m; ++i) {
    cin >> n[i] >> l[i] >> r[i];
    N += n[i];
    L += l[i], R += r[i];
    a[i].resize(n[i]);
    c[i].resize(n[i]);
    for (auto &j : a[i])
      cin >> j;
    for (auto &j : c[i])
      cin >> j;
    for (int j = 0; j < n[i]; ++j) {
      sum[i] += c[i][j];
      mp[a[i][j]].emplace_back(i, c[i][j]);
    }
  }
  if (L + N < R) {
    cout << "0\n";
    return;
  }
  ll ans = 1e18;
  for (ll x = L; x <= R; ++x) {
    if (!mp.contains(x)) {
      cout << "0\n";
      return;
    }
  }
  for (ll x = L; x <= R; ++x) {
    ll cnt = 0;
    ll cur = R;
    for (auto &[i, num] : mp[x]) {
      cur -= r[i];
      cnt += max(l[i] - (sum[i] - num), 0LL);
      cur += max(l[i], min(r[i], sum[i] - num));
    }
    if (cur < x)
      cnt += x - cur;
    ans = min(ans, cnt);
  }
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