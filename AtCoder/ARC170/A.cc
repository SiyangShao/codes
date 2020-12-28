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
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << "0\n";
  }
  deque<int> a, b;
  int aMin = n, bMax = -1;
  for (int i = 0; i < n; ++i) {
    if (t[i] == 'A')
      aMin = min(aMin, i);
    else
      bMax = max(bMax, i);
    if (s[i] == t[i])
      continue;
    if (t[i] == 'A')
      a.emplace_back(i);
    else
      b.emplace_back(i);
  }
  int ans = 0;
  while (!a.empty() && !b.empty()) {
    if (a.front() < b.front()) {
      a.pop_front();
      b.pop_front();
      ans++;
      continue;
    }
    if (b.front() > aMin) {
      b.pop_front();
      ans++;
      continue;
    }
    cout << "-1\n";
    return;
  }
  if (!a.empty()) {
    if (a.back() > bMax) {
      cout << "-1\n";
      return;
    }
    ans += (int)a.size();
  }
  if (!b.empty()) {
    if (b.front() < aMin) {
      cout << "-1\n";
      return;
    }
    ans += (int)b.size();
  }
  cout << ans << "\n";
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