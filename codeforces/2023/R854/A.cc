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
  int n, m;
  cin >> n >> m;
  vector<int> p(m);
  vector<int> in(n + m + 1, 0);
  vector<int> ans(n + 1, -1);
  for (auto &i : p)
    cin >> i;
  set<pair<int, int>> st;
  for (int i = 1; i <= n; ++i) {
    st.emplace(n - i + 1, i);
    in[i] = i;
  }
  int t = n + 1;
  for (int i = 0; i < m; ++i) {
    if (in[p[i]]) {
      st.erase({in[p[i]], p[i]});
    } else {
      auto it = st.begin();
      in[it->second] = 0;
      if (it->second <= n) {
        ans[it->second] = t - n;
      }
      st.erase(it);
    }
    in[p[i]] = t++;
    st.emplace(in[p[i]], p[i]);
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n"[i == n];
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