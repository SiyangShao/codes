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
  string s, t;
  cin >> s >> t;
  array<deque<int>, 26> pos;
  for (int i = 0; i < n; ++i) {
    pos[s[i] - 'a'].emplace_back(i);
  }
  for (auto ch : t) {
    if (pos[ch - 'a'].empty()) {
      cout << "NO\n";
      return;
    }
    int id = pos[ch - 'a'].front();
    pos[ch - 'a'].pop_front();
    for (int i = 0; i < ch - 'a'; ++i) {
      while (!pos[i].empty() && pos[i].front() < id) {
        pos[i].pop_front();
      }
    }
  }
  cout << "YES\n";
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