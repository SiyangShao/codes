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
  string s;
  cin >> s;
  int n = static_cast<int>(s.length());
  ll pos;
  cin >> pos;
  pos--;
  function<void(int)> cal = [&](int del) {
    string t;
    for (auto c : s) {
      while (del and not t.empty() and c < t.back()) {
        t.pop_back();
        del--;
      }
      t += c;
    }
    cout << t[pos];
  };
  for (int i = 0; i < n; ++i) {
    int len = n - i;
    if (pos < len) {
      cal(i);
      return;
    }
    pos -= len;
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