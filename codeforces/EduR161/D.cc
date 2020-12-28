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
  vector<ll> a(n), d(n), l(n), r(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : d)
    cin >> i;
  for (int i = 0; i < n; ++i) {
    l[i] = i - 1, r[i] = i + 1;
  }
  vector<ll> ans(n);
  auto it = ans.begin();
  vector<ll> del;
  for (int i = 0; i < n; ++i) {
    ll sum = 0;
    if (i > 0)
      sum += a[i - 1];
    if (i + 1 < n)
      sum += a[i + 1];
    if (sum > d[i]) {
      del.emplace_back(i);
    }
  }
  vector<int> alreadyDel(n);
  while (!del.empty()) {
    dbg(del);
    *it = (ll)del.size();
    it++;
    vector<int> originLef, originRig;
    for (auto i : del) {
      alreadyDel[i] = 1;
      if (l[i] >= 0)
        originLef.emplace_back(l[i]);
      if (r[i] < n)
        originRig.emplace_back(r[i]);
    }
    for (auto i : del) {
      if (r[i] < n)
        l[r[i]] = l[i];
      if (l[i] >= 0)
        r[l[i]] = r[i];
    }
    del.clear();
    for (auto i : originLef) {
      if (alreadyDel[i])
        continue;
      ll sum = 0;
      if (l[i] >= 0)
        sum += a[l[i]];
      if (r[i] < n)
        sum += a[r[i]];
      if (sum > d[i]) {
        del.emplace_back(i);
      }
    }
    for (auto i : originRig) {
      if (alreadyDel[i])
        continue;
      ll sum = 0;
      if (l[i] >= 0)
        sum += a[l[i]];
      if (r[i] < n)
        sum += a[r[i]];
      if (sum > d[i]) {
        del.emplace_back(i);
      }
    }
    ranges::sort(del);
    del.erase(unique(del.begin(), del.end()), del.end());
  }
  for (auto i : ans) {
    cout << i << " ";
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