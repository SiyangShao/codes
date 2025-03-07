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
  vector<tuple<int, int, int, int>> ans(n);
  for (int i = 0; i < n; ++i) {
    string fi, push, gt;
    int x, y, a, b;
    cin >> fi;
    if (fi == "HALT;") {
      cin >> push >> x >> gt >> y;
      y--;
      ans[i] = {-1, -1, x, y};
    } else {
      string tmp;
      cin >> x >> gt >> tmp;
      y = stoi(tmp.substr(0, tmp.size() - 1));
      cin >> push >> a >> gt >> b;
      y--, b--;
      ans[i] = {x, y, a, b};
    }
  }
  map<int, pair<int, int>> push_map;
  set<int> push_set;
  function<void(int)> push = [&](int line) {
    if (push_map.contains(line))
      return;
    if (push_set.contains(line)) {
      // it is a loop
      cout << "-1\n";
      exit(0);
    }
    push_set.emplace(line);
    // assume it is always push
    auto [x, y, a, b] = ans[line];
    // push a in the stack
    // check line b is push or not
    int cur = b;
    auto [x2, y2, a2, b2] = ans[cur];
    int base = 2;
    while (x2 != a) {
      push(cur);
      auto [val, nxt] = push_map[cur];
      auto [x3, y3, a3, b3] = ans[nxt];
      cur = nxt;
      x2 = x3, y2 = y3, a2 = a3, b2 = b3;
      base += val;
    }
    push_map[line] = {base, y2};
    push_set.erase(line);
  };
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