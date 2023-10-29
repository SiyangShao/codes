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
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto dif = a;
  for (int i = 1; i < n; ++i) {
    dif[i] = a[i] - a[i - 1];
  }
  map<int, ll> mp;
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    ll x;
    cin >> l >> r >> x;
    l--;
    mp[l] += x, mp[r] -= x;
    if (mp[l] == 0) {
      mp.erase(l);
    }
    if (mp[r] == 0) {
      mp.erase(r);
    }
    if (mp.empty() || (mp.begin()->second) > 0)
      continue;
    for (auto [i, j] : mp) {
      if (i < n)
        dif[i] += j;
    }
    mp.clear();
  }
  for (int i = 0; i < n; ++i) {
    if (i != 0)
      dif[i] += dif[i - 1];
    cout << dif[i] << " ";
  }
  cout << "\n";
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