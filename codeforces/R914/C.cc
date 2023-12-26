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
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  if (k >= 3) {
    cout << "0\n";
  } else if (k == 1) {
    ll ans = *min_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans = min(ans, abs(a[i] - a[j]));
      }
    }
    cout << ans << "\n";
  } else {
    set<ll> st;
    for (auto i : a) {
      st.emplace(i);
    }
    ll ans = *min_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ll cur = abs(a[i] - a[j]);
        ans = min(ans, cur);
        auto it = st.lower_bound(cur);
        if (it != st.end()) {
          ans = min(ans, *it - cur);
        }
        if (it != st.begin()) {
          it = prev(it);
          ans = min(ans, cur - *it);
        }
      }
    }
    cout << ans << "\n";
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