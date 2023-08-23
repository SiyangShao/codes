#include <bits/stdc++.h>
#define ONLINE_JUDGE
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
  string s, t;
  cin >> s >> t;
  int cnt = 0;
  vector<int> seg;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      cnt++;
    } else {
      if (cnt != 0) {
        seg.emplace_back(cnt);
      }
      cnt = 0;
    }
  }
  if (cnt != 0) {
    seg.emplace_back(cnt);
  }
  if ((int)seg.size() >= 3) {
    cout << "0\n";
  } else if (seg.empty()) {
    cout << (ll)n * (n + 1LL) / 2 << "\n";
  } else if ((int)seg.size() == 1) {
    cnt = seg[0];
    if (cnt == 1 && n == 1) {
      cout << "0\n";
    } else {
      cout << 2 * (cnt - 1) + 2 * (n - cnt) << "\n";
    }
  } else {
    cout << "6\n";
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