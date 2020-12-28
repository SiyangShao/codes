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
  vector<ll> l(n), r(n), c(n);
  for (auto &i : l)
    cin >> i;
  multiset<ll> st;
  for (auto &i : r) {
    cin >> i;
    st.emplace(i);
  }
  for (auto &i : c)
    cin >> i;
  ranges::sort(l);
  vector<ll> dif;
  for (auto i : ranges::views::reverse(l)) {
    auto it = st.lower_bound(i);
    dif.emplace_back(*it - i);
    st.erase(it);
  }
  ranges::sort(dif, greater());
  ranges::sort(c);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += c[i] * dif[i];
  }
  cout << ans << "\n";
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