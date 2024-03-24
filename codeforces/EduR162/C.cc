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
  int n, q;
  cin >> n >> q;
  vector<ll> c(n);
  for (auto &i : c)
    cin >> i;
  vector<ll> cnt(n + 1), sum(n + 1);
  for (int i = 1; i <= n; ++i) {
    cnt[i] = cnt[i - 1];
    if (c[i - 1] == 1)
      cnt[i]++;
    sum[i] = sum[i - 1] + c[i - 1] - 1;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "NO\n";
      continue;
    }
    ll oneCount = cnt[r] - cnt[l - 1];
    ll canDel = sum[r] - sum[l - 1];
    dbg(canDel, oneCount);
    if (canDel >= oneCount) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
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