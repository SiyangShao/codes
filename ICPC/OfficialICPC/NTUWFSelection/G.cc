#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
ll n, k;
ll les;
vector<ll> a;
void dfs(int id, ll sum) {
  if (id == n || les >= k)
    return;
  if (sum - a[id] >= 0) {
    les++;
    dfs(id + 1, sum - a[id]);
    dfs(id + 1, sum);
  }
}
auto solve() {
  cin >> n >> k;
  a = vector<ll>(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll l = 1, r = 2e9;
  ranges::sort(a);
  ll ans = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    les = 0;
    dfs(0, mid);
    if (les < k) {
      l = mid + 1;
      ans = max(ans, l);
    } else {
      r = mid - 1;
    }
  }
  cout << ans << "\n";
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