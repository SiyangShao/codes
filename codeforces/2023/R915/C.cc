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
  deque<char> cur;
  for (auto i : s) {
    while (!cur.empty() && cur.back() < i) {
      cur.pop_back();
    }
    cur.emplace_back(i);
  }
  dbg(cur);
  auto itb = cur.begin();
  auto ite = cur.rbegin();
  for (auto &i : s) {
    if (i == *itb) {
      i = *ite;
      itb++;
      ite++;
    }
  }
  if (is_sorted(s.begin(), s.end())) {
    int rep = 0;
    for (auto i : cur) {
      if (i == cur.front())
        rep++;
      else
        break;
    }
    cout << cur.size() - rep << "\n";
  } else {
    cout << "-1\n";
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