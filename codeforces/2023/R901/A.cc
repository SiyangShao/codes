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
  int n, m, k;
  cin >> n >> m >> k;
  multiset<ll> a, b;
  for (int i = 0; i < n; ++i) {
    ll u;
    cin >> u;
    a.emplace(u);
  }
  for (int i = 0; i < m; ++i) {
    ll u;
    cin >> u;
    b.emplace(u);
  }
  multiset<ll> prea = a, preb = b;
  bool flag = false;
  if (k % 2 == 1) {
    k--;
    flag = true;
  }
  dbg(a, b);
  for (int i = 0; i < k; i += 2) {
    auto u = *a.begin();
    auto v = *b.rbegin();
    if (v > u) {
      a.erase(a.find(u)), b.erase(b.find(v));
      a.emplace(v), b.emplace(u);
    }
    u = *a.rbegin();
    v = *b.begin();
    if (u > v) {
      a.erase(a.find(u)), b.erase(b.find(v));
      a.emplace(v), b.emplace(u);
    }
    if (a == prea && b == preb) {
      break;
    }
    prea = a, preb = b;
  }
  dbg(a, b);
  if (flag) {
    auto u = *a.begin();
    auto v = *b.rbegin();
    if (v > u) {
      a.erase(a.find(u)), b.erase(b.find(v));
      a.emplace(v), b.emplace(u);
    }
  }
  dbg(a, b);
  ll ans = 0;
  for (auto i : a) {
    ans += i;
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