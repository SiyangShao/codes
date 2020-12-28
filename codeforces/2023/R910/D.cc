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
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  ll ans = 0;
  vector<pair<ll, ll>> vecx, vecy;
  ll mxa = 0, mxb = 0, mia = 1e9 + 7, mib = 1e9 + 7;
  for (int i = 0; i < n; ++i) {
    ans += abs(a[i] - b[i]);
    if (a[i] >= b[i]) {
      vecx.emplace_back(a[i], b[i]);
      mxb = max(mxb, b[i]);
      mia = min(mia, a[i]);
    }
    if (a[i] <= b[i]) {
      vecy.emplace_back(b[i], a[i]);
      mib = min(mib, b[i]);
      mxa = max(mxa, a[i]);
    }
  }
  ll add = 0;
  add = max({0LL, 2 * (mxb - mib), 2 * (mxa - mia)});
  auto case2 = [](vector<pair<ll, ll>> &vec) {
    if (vec.empty())
      return 0LL;
    sort(vec.begin(), vec.end(), greater<>());
    auto [cury, curx] = vec.front();
    ll base = 0;
    for (auto [y, x] : vec) {
      base = max(base, 2 * (curx - y));
      curx = max(curx, x);
    }
    return base;
  };
  add = max({add, case2(vecx), case2(vecy)});
  cout << ans + add << "\n";
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