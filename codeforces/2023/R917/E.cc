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
  int n, k;
  cin >> n >> k;
  if (k % 2 == 1) {
    cout << "No\n";
    return;
  }
  if (n == 2) {
    cout << "Yes\n";
    if (k == 0) {
      cout << "0 0\n0 0\n";
    } else if (k == 2) {
      cout << "1 0\n0 1\n";
    } else {
      cout << "1 1\n1 1\n";
    }
    return;
  }
  if (k == 2 || k == n * n - 2) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  if (k % 4 == 0) {
    k /= 4;
    set<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (st.contains({i / 2, j / 2})) {
          cout << "1 ";
        } else if (k) {
          k--;
          st.emplace(i / 2, j / 2);
          cout << "1 ";
        } else {
          cout << "0 ";
        }
      }
      cout << "\n";
    }
    assert(k == 0);
  } else {
    if (k == n * n - 6) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if ((i == 0 && j < 2) || (i == 1 && (j == 0 || j == 2)) ||
              (i == 2 && (j >= 1 && j <= 2))) {
            cout << "0 ";
          } else {
            cout << "1 ";
          }
        }
        cout << "\n";
      }
    } else {
      k -= 6;
      k /= 4;
      set<pair<int, int>> st;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if ((i == 0 && j < 2) || (i == 1 && (j == 0 || j == 2)) ||
              (i == 2 && (j >= 1 && j <= 2))) {
            cout << "1 ";
          } else if (i < 4 && j < 4) {
            cout << "0 ";
          } else if (st.contains({i / 2, j / 2})) {
            cout << "1 ";
          } else if (k) {
            k--;
            st.emplace(i / 2, j / 2);
            cout << "1 ";
          } else {
            cout << "0 ";
          }
        }
        cout << "\n";
      }
      assert(k == 0);
    }
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