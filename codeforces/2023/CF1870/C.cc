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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  vector<int> posl(k, n), posr(k, -1);
  set<pair<int, int>> l, r;
  for (int i = 0; i < n; ++i) {
    posl[a[i]] = min(posl[a[i]], i);
    posr[a[i]] = max(posr[a[i]], i);
  }
  for (int i = 0; i < k; ++i) {
    l.emplace(posl[i], i);
    r.emplace(posr[i], i);
  }
  for (int i = 0; i < k; ++i) {
    // all i >= k, min posl[k] and max posr[k]
    auto [pl, il] = *l.begin();
    auto [pr, ir] = *r.rbegin();
    if (posl[i] == n || posr[i] == -1) {
      cout << 0 << " ";
    } else {
      cout << 2 * (pr - pl + 1) << " ";
      assert(2 * (pr - pl + 1) > 0);
    }
    l.erase({posl[i], i});
    r.erase({posr[i], i});
  }
  cout << "\n";
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