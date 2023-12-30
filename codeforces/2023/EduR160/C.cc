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
  int m;
  cin >> m;
  array<int, 35> status;
  fill(status.begin(), status.end(), 0);
  function<void(int)> upd = [&](int x) { status[x]++; };
  function<bool(ll)> check = [&](ll x) {
    auto s = status;
    for (int i = 0; i < 35; ++i) {
      if (((x >> i) & 1) == 1) {
        s[i]--;
      }
      if (s[i] < 0)
        return false;
      if (i + 1 != 35) {
        s[i + 1] += s[i] / 2;
      }
    }
    return true;
  };
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int v;
      cin >> v;
      upd(v);
    } else {
      ll v;
      cin >> v;
      if (check(v)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
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