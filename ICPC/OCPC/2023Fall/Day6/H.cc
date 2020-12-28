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
  map<pair<ll, ll>, vector<ll>> LefFix, RigFix;
  function<void(ll, ll)> dfs = [&](ll x, ll y) {
    if (x == 0 || y == 0)
      return;
    if (x >= y) {
      ll res = x % y;
      ll a = x / y;
      RigFix[{res, y}].emplace_back(a + 1);
      dfs(res, y - res);
    } else {
      ll res = y % x;
      ll a = y / x;
      LefFix[{res, x}].emplace_back(a + 1);
      dfs(x - res, res);
    }
  };
  function<ll(ll, ll)> calL = [&](ll x, ll y) {
    ll res = x % y;
    ll a = x / y;
    if (RigFix.find({res, y}) == RigFix.end())
      return 0LL;
    auto &&vec = RigFix[{res, y}];
    auto it = lower_bound(vec.begin(), vec.end(), a + 1);
    return (ll)(vec.end() - it);
  };
  function<ll(ll, ll)> calR = [&](ll x, ll y) {
    ll res = y % x;
    ll a = y / x;
    if (LefFix.find({res, x}) == LefFix.end())
      return 0LL;
    auto &&vec = LefFix[{res, x}];
    auto it = lower_bound(vec.begin(), vec.end(), a + 1);
    return (ll)(vec.end() - it);
  };
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    dfs(a, b);
  }
  for (auto &[_, vec] : LefFix) {
    sort(vec.begin(), vec.end());
  }
  for (auto &[_, vec] : RigFix) {
    sort(vec.begin(), vec.end());
  }
  for (int i = 0; i < q; ++i) {
    ll a, b;
    cin >> a >> b;
    cout << calL(a, b) + calR(a, b) << "\n";
  }
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