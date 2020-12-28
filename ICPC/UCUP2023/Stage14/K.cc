#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 2e5;
int n, k;
array<int, N> sol, a;
set<pair<int, int>> st;
bool possible(int x) {
  st.clear();
  for (int i = 1; i <= k; ++i) {
    st.emplace(0, i);
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      auto [u, v] = *st.begin();
      if (u == x)
        return false;
      sol[i] = v;
      st.erase(st.begin());
      st.emplace(u + 1, v);
    } else {
      auto [u, v] = *prev(st.end());
      st.erase(prev(st.end()));
      sol[i] = v;
      st.emplace(u >= 1 ? u - 1 : 0, v);
    }
  }
  return true;
}
auto solve() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int lo = 0, hi = n;
  int ans = n;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (possible(mid)) {
      ans = min(ans, mid);
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  bool flag = possible(ans);
  assert(flag);
  for (int i = 0; i < n; ++i) {
    cout << sol[i] << " ";
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