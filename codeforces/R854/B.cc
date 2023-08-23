#include <bits/stdc++.h>
#include <queue>
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
  vector<pair<int, int>> a(n);
  for (int x = 0; auto &[l, r] : a) {
    cin >> l;
    r = ++x;
  }
  if (n == 1) {
    cout << "0\n";
    return;
  }
  sort(a.begin(), a.end());
  if (a[0].first == 1) {
    if (a[n - 1].first == 1) {
      cout << "0\n";
    } else {
      cout << "-1\n";
    }
    return;
  }
  if (a[0].first == a[n - 1].first) {
    cout << "0\n";
    return;
  }
  vector<pair<int, int>> ans;
  auto cal = [&](auto &l, auto &r) {
    while (l.first != r.first) {
      if (l.first < r.first)
        swap(l, r);
      ans.emplace_back(l.second, r.second);
      l.first = (l.first + r.first - 1) / r.first;
    }
  };
  while (true) {
    sort(a.begin(), a.end());
    bool flag = false;
    for (int i = 1; i < n; ++i) {
      if (a[i].first != a[i - 1].first) {
        cal(a[i], a[i - 1]);
        flag = true;
        break;
      }
    }
    if (flag)
      continue;
    break;
  }
  cout << ans.size() << "\n";
  for (auto &[l, r] : ans) {
    cout << l << " " << r << "\n";
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