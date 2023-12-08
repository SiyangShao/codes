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
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  while (!a.empty()) {
    auto it = max_element(a.begin(), a.end());
    if (it == a.begin()) {
      if ((int)a.size() == 1) {
        cout << "YES\n";
        return;
      } else {
        cout << "NO\n";
        return;
      }
    }
    a.erase(it);
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