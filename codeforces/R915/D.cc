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
  for (auto &i : a)
    cin >> i;
  int beg = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      beg = i;
      break;
    }
  }
  ll ans = 0, base = 0;
  stack<pair<ll, ll>> st;
  st.emplace(0, 0);
  for (int offset = 1; offset < n; ++offset) {
    int cur = beg + offset >= n ? beg + offset - n : beg + offset;
    while (st.top().first > a[cur]) {
      auto [val, id] = st.top();
      st.pop();
      base -= val * (id - st.top().second);
    }
    base += (ll)a[cur] * (offset - st.top().second);
    st.emplace(a[cur], offset);
    ans = max(ans, base);
  }
  cout << ans + n << "\n";
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