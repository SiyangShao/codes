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
  vector<tuple<ll, ll, ll, ll, ll, char>> ops;
  while (n--) {
    string s;
    cin >> s;
    if (s == "Circle") {
      ll x, y, r;
      cin >> x >> y >> r;
      char col;
      cin >> col;
      ops.emplace_back(0, 0, x, y, r, col);
    } else if (s == "Rectangle") {
      ll x1, y1, x2, y2;
      char col;
      cin >> x1 >> y1 >> x2 >> y2 >> col;
      ops.emplace_back(1, x1, y1, x2, y2, col);
    } else {
      ll x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      for (ll y = y2; y >= y1; --y) {
        for (ll x = x1; x <= x2; ++x) {
          char output = '.';
          for (auto typ : ops) {
            if (get<0>(typ) == 0) {
              auto [_, _2, u, v, r, col] = typ;
              if ((x - u) * (x - u) + (y - v) * (y - v) <= r * r)
                output = col;
            } else {
              auto [_, u1, v1, u2, v2, col] = typ;
              if (x >= u1 && x <= u2 && y >= v1 && y <= v2)
                output = col;
            }
          }
          cout << output;
        }
        cout << "\n";
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