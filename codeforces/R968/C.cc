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
  vector<int> num(26);
  for (auto i : s) {
    num[i - 'a']++;
  }
  priority_queue<pair<int, int>> Q;
  for (int i = 0; i < 26; ++i) {
    if (num[i]) {
      Q.emplace(num[i], i);
    }
  }
  int p = -1;
  for (int i = 0; i < n; ++i) {
    auto tp = Q.top();
    Q.pop();
    if (tp.second != p) {
      cout << char('a' + tp.second);
      tp.first--;
      if (tp.first) {
        Q.push(tp);
      }
      p = tp.second;
    } else {
      if (Q.empty()) {
        for (int j = i; j < n; ++j) {
          cout << char('a' + tp.second);
        }
        cout << "\n";
        return;
      } else {
        auto tp2 = Q.top();
        Q.pop();
        cout << char('a' + tp2.second);
        tp2.first--;
        if (tp2.first) {
          Q.push(tp2);
        }
        Q.push(tp);
        p = tp2.second;
      }
    }
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