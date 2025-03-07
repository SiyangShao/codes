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
  vector<tuple<int, int, int, int>> ans(n);
  for (auto& [a, b, c, d] : ans) {
    cin >> a >> b >> c >> d;
  }
  stack<int> st;
  int total_op = 0;
  function<void(int)> exe = [&](int cur_len) {
    auto [a, b, c, d] = ans[cur_len - 1];
    if (a == -1) {
      assert(st.empty());
      total_op++;
      return;
    } else {
      if (!st.empty() && st.top() == a) {
        st.pop();
        total_op++;
        exe(b);
      } else {
        st.push(c);
        total_op++;
        exe(d);
      }
    }
  };
  exe(1);
  cout << total_op << endl;
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}