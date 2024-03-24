#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
bool ask(int u, int v) {
  cout << "? " << u + 1 << " " << v + 1 << "\n";
  cout.flush();
  int ans;
  cin >> ans;
  return ans == 1;
}
void final(int u, int v, int n) {
  // assert there's edge between u-v
  int fi = -1, se = -1;
  for (int i = 0; i < n; ++i) {
    if (i == u || i == v)
      continue;
    if (fi == -1)
      fi = i;
    else
      se = i;
  }
  if (ask(u, fi)) {
    if (ask(u, se)) {
      cout << "! 2\n";
    } else {
      cout << "! 1\n";
    }
  } else {
    if (ask(v, fi)) {
      if (ask(v, se)) {
        cout << "! 2\n";
      } else {
        cout << "! 1\n";
      }
    } else {
      cout << "! 1\n";
    }
  }
  cout.flush();
}
auto solve() {
  int n;
  cin >> n;
  for (int i = 0; i + 1 < n; i += 2) {
    if (ask(i, i + 1)) {
      final(i, i + 1, n);
      return;
    }
  }
  if (ask(n - 2, n - 1)) {
    final(n - 2, n - 1, n);
    return;
  }
  cout << "! 1\n";
  cout.flush();
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