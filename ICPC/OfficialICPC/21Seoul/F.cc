#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
#define int ll
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  ranges::sort(a, greater<>());
  vector<int> b(n);
  for (auto &i : b)
    cin >> i;
  ranges::sort(b, greater<>());
  function<pair<bool, int>(int)> check_rev = [&](int x) {
    int num = 0, output = a.front();
    auto it = a.begin();
    int take = 0;
    for (auto i : b) {
      int l = i - x, r = i + x;
      while (it != a.end() && *it > r) {
        output = min(output, *it);
        take++;
        it++;
      }
      if (it == a.end() || *it < l) {
        num++;
      } else {
        it++;
      }
    }
    if (num == 0) {
      return pair<bool, int>{true, a.back()};
    } else if (num == 1) {
      if (take == 0) {
        assert(it != a.end());
        output = a.back();
      } else {
        assert(take == 1);
      }
      return pair<bool, int>{true, output};
    } else {
      return pair<bool, int>{false, -1};
    }
  };
  int l = 0, r = max(b.front(), a.front());
  int ans = r, output = a.back();
  while (l <= r) {
    int mid = (l + r) / 2;
    // auto [x, y] = check(mid);
    auto [c, d] = check_rev(mid);
    if (c) {
      if (ans > mid) {
        ans = mid;
        output = d;
      }
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  dbg(ans);
  cout << output << "\n";
}
auto main() -> signed {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}