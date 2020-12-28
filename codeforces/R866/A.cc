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
  set<int> st;
  for (auto &i : a) {
    cin >> i;
    st.emplace(i);
  }
  int mex = 0;
  while (st.contains(mex)) {
    mex++;
  }
  dbg("MEX now is", mex, "MEX should be", mex + 1);
  if (mex == n) {
    cout << "No\n";
    return;
  }
  // must change sth into mex
  // first find is there anything about mex + 1
  int l = -1, r = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == mex + 1) {
      l = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == mex + 1) {
      r = i;
      break;
    }
  }
  if (l == -1) {
    cout << "Yes\n";
    return;
  }
  st.clear();
  for (int i = 0; i < l; ++i) {
    st.emplace(a[i]);
  }
  for (int i = r + 1; i < n; ++i) {
    st.emplace(a[i]);
  }
  int mex2 = 0;
  while (st.contains(mex2)) {
    mex2++;
  }
  if (mex2 == mex) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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