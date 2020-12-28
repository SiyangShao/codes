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
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  vector<tuple<int, int, int>> state;
  state.emplace_back(0, n, n);
  for (auto i : a) {
    vector<tuple<int, int, int>> nxtState;
    for (auto [cost, x, y] : state) {
      if (x < y)
        swap(x, y);
      if (i > x && i > y) {
        nxtState.emplace_back(cost + 1, i, max(x, y));
      } else if (i <= x && i <= y) {
        nxtState.emplace_back(cost, i, max(x, y));
      } else {
        assert(x >= i && i > y);
        nxtState.emplace_back(cost, i, y);
        nxtState.emplace_back(cost + 1, i, x);
      }
    }
    ranges::sort(nxtState);
    state.clear();
    tuple<int, int, int> lef, rig;
    lef = {-1, -1, -1}, rig = {-1, -1, -1};
    for (auto [cost, x, y] : nxtState) {
      if (cost == get<0>(nxtState[0])) {
        lef = max(lef, {cost, x, y});
      } else if (cost == get<0>(nxtState[0]) + 1) {
        rig = max(rig, {cost, x, y});
      }
    }
    state.emplace_back(lef);
    if (get<0>(rig) != -1) {
      state.emplace_back(rig);
    }
  }
  ranges::sort(state);
  cout << get<0>(state[0]) << "\n";
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