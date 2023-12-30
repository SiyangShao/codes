#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
auto solve() {
  string a, b;
  cin >> a >> b;
  if (*a.begin() == *b.begin()) {
    cout << "YES\n";
    cout << *a.begin() << "*"
         << "\n";
  } else if (a.back() == b.back()) {
    cout << "YES\n";
    cout << "*" << a.back() << "\n";
  } else {
    set<string> st;
    for (int i = 0; i + 1 < (int)a.length(); ++i) {
      st.emplace(a.substr(i, 2));
    }
    for (int i = 0; i + 1 < (int)b.length(); ++i) {
      string tmp = b.substr(i, 2);
      if (st.contains(tmp)) {
        cout << "YES\n";
        cout << "*" << tmp << "*"
             << "\n";
        return;
      }
    }
    cout << "NO\n";
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