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

  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  stack<ll> s;
  vector<ll> l(n + 1), r(n + 1);
  for (ll i = 1; i <= n; ++i) {
    while (!s.empty() && a[s.top()] >= a[i])
      s.pop();
    if (!s.empty())
      l[i] = s.top();
    else
      l[i] = 0;
    s.emplace(i);
  }
  while (!s.empty())
    s.pop();
  for (ll i = n; i >= 1; --i) {
    while (!s.empty() && a[s.top()] >= a[i])
      s.pop();
    if (!s.empty())
      r[i] = s.top();
    else
      r[i] = n + 1;
    s.emplace(i);
  }
  dbg(a, l, r);
  ll ans = 0;
  ll L = n + 1, R = n + 1;
  for (ll i = 1; i <= n; ++i) {
    ll cur = a[i] * (r[i] - l[i] - 1);
    dbg(i, a[i], cur, l[i], r[i]);
    if (ans < cur) {
      ans = cur;
      L = l[i], R = r[i];
    } else if (ans == cur) {
      if (L > l[i]) {
        L = l[i];
        R = r[i];
      }
    }
  }
  cout << L + 1 << " " << R - 1 << " " << ans << "\n";
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