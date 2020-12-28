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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b)
    cin >> i;
  ranges::sort(a, greater<>());
  ranges::sort(b, greater<>());
  ll cnt = 0;
  multiset<ll> a_all, a_m, b_m;
  for (int i = 0; i < m; ++i) {
    if (a[i] > b[i]) {
      cout << "-1\n";
      return;
    }
    b_m.emplace(b[i]);
    a_m.emplace(a[i]);
    cnt += b[i] - a[i];
  }
  if (cnt > n - m) {
    cout << "-1\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    a_all.emplace(a[i]);
  }
  vector<ll> output;
  while (true) {
    ll dif = static_cast<ll>(a_all.size()) - static_cast<ll>(b_m.size());
    dbg(a_all, b_m, cnt, output);
    if (dif < cnt) {
      cout << "-1\n";
      return;
    } else if (dif == cnt) {
      vector<int> a_rev, b_rev;
      for (auto i : a_all) {
        a_rev.emplace_back(i);
      }
      for (auto i : b_m) {
        b_rev.emplace_back(i);
      }
      ranges::reverse(a_rev);
      ranges::reverse(b_rev);
      for (int i = m - 1; i >= 0; --i) {
        if (a_rev[i] > b_rev[i]) {
          cout << "-1\n";
          return;
        }
        while (a_rev[i] < b_rev[i]) {
          output.emplace_back(a_rev[i]);
          a_rev[i]++;
        }
      }
      cout << output.size() << "\n";
      for (auto i : output) {
        cout << i << " ";
      }
      cout << "\n";
      return;
    } else {
      ll mi = *a_all.begin();
      if (mi == *a_m.begin()) {
        a_m.erase(a_m.find(mi));
        a_m.emplace(mi + 1);
        cnt--;
      }
      if (cnt < 0) {
        cout << "-1\n";
        return;
      }
      output.emplace_back(mi);
      a_all.erase(a_all.begin());
      a_all.emplace(mi + 1);
      a_all.erase(a_all.begin());
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