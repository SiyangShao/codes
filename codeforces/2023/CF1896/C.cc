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
  vector<int> a(n), b(n);
  for (auto &i : a)
    cin >> i;
  multiset<int> st;
  for (auto &i : b) {
    cin >> i;
    st.emplace(i);
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  ranges::sort(id, [&](int i, int j) { return a[i] > a[j]; });
  vector<int> ans(n);
  for (int i = k - 1; i >= 0; --i) {
    int cur = a[id[i]];
    if (cur > *st.begin()) {
      ans[id[i]] = *st.begin();
      st.erase(st.begin());
    } else {
      cout << "No\n";
      return;
    }
  }
  for (int i = n - 1; i >= k; --i) {
    int cur = a[id[i]];
    if (cur > *st.begin()) {
      cout << "No\n";
      return;
    } else {
      ans[id[i]] = *st.begin();
      st.erase(st.begin());
    }
  }
  cout << "Yes\n";
  for (auto i : ans) {
    cout << i << " ";
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