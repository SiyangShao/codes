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
  ll one = 0, op = 0;
  reverse(s.begin(), s.end());
  vector<ll> ans;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      op += one;
      ans.emplace_back(op);
    } else {
      one++;
    }
  }
  for (auto i : ans) {
    cout << i << " ";
  }
  for (int i = (int)ans.size(); i < n; ++i) {
    cout << "-1 ";
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