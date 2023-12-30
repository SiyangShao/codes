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
  priority_queue<char, vector<char>, greater<>> Q;
  for (auto i : s) {
    Q.emplace(i);
  }
  string l = "", r = "";
  while (!Q.empty()) {
    if (Q.size() == 1) {
      l += Q.top();
      Q.pop();
    } else {
      auto x = Q.top();
      Q.pop();
      auto y = Q.top();
      Q.pop();
      if (x == y) {
        l += x;
        r += y;
      } else {
        // l += x;
        // x < y
        // r += y;
        string cur = "";
        while (!Q.empty()) {
          cur += Q.top();
          Q.pop();
        }
        if (cur.empty() || cur.back() == y) {
          int len = (int)cur.length() + 1;
          for (int i = 1; i <= len / 2; ++i) {
            l += y;
          }
          l += x;
          for (int i = len / 2 + 1; i <= len; ++i) {
            l += y;
          }
        } else {
          l += x;
          r += y;
          r += cur;
        }
      }
    }
  }
  reverse(r.begin(), r.end());
  string ans = l + r;
  auto nxt = ans;
  reverse(nxt.begin(), nxt.end());
  cout << max(ans, nxt) << "\n";
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