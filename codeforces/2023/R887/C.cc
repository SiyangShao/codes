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
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  ll pre = 0;
  priority_queue<ll, vector<ll>, greater<>> Q;
  ll ans = 0;
  for (auto &i : a) {
    cin >> i;
    if (i == k)
      i -= k;
    if (i > pre) {
      Q.emplace(i - pre);
      ans += Q.top();
      Q.pop();
    } else {
      Q.emplace(i + k - pre);
    }
    pre = i;
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