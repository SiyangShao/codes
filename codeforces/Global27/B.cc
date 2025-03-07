#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...)                                                               \
  {}
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  // divisible by 3 (of cause), 11 and 2
  // last digit is 6
  // divisible by 11: odd sum - even sum is divisible by 11
  if (n % 2 == 0) {
    for (int i = 0; i + 2 < n; ++i) {
      cout << "3";
    }
    cout << "66\n";
  } else {
    if (n == 1 || n == 3) {
      cout << "-1\n";
    } else {
      for (int i = 0; i + 4 < n; ++i) {
        cout << "3";
      }
      cout << "6366\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
