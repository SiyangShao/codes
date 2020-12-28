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
  string s;
  cin >> s;
  vector<int> sa(1 << n), rk(1 << (n)), tmp(1 << (n));
  iota(sa.begin(), sa.end(), 0);
  for (int i = 0; i < (1 << n); i++) {
    rk[i] = s[i] - 'a';
  }
  for (int bs = 0; bs < n; bs++) {
    const int k = 1 << bs;
    sort(sa.begin(), sa.end(), [&](int i, int j) {
      if (rk[i] != rk[j]) {
        return rk[i] < rk[j];
      }
      return rk[k ^ i] < rk[k ^ j];
    });
    tmp = rk;
    rk[sa[0]] = 0;
    for (int p = 0, i = 1; i < (1 << n); ++i) {
      if (tmp[sa[i]] == tmp[sa[i - 1]] &&
          tmp[sa[i] ^ k] == tmp[sa[i - 1] ^ k]) {
        rk[sa[i]] = p;
      } else {
        rk[sa[i]] = ++p;
      }
    }
    dbg(sa);
  }
  for (int i = 0; i < (1 << n); ++i) {
    cout << s[i ^ sa[0]];
  }
  cout << "\n";
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