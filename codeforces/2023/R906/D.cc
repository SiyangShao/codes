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
  vector<stack<int>> c(n);
  for (auto &i : c) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int u;
      cin >> u;
      u--;
      i.emplace(u);
    }
  }
  stack<int> st;
  vector<bool> in_st(n, false);
  vector<int> ans(n, -1);
  function<int(int)> dfs = [&](int u) {
    if (ans[u] != -1)
      return ans[u];
    if (c[u].empty())
      return u;
    if (in_st[u]) {
      while (true) {
        auto v = st.top();
        st.pop();
        c[v].pop();
        in_st[v] = false;
        if (v == u)
          break;
      }
      return dfs(u);
    }
    in_st[u] = true;
    st.emplace(u);
    return dfs(c[u].top());
  };
  for (int i = 0; i < n; ++i) {
    ans[i] = dfs(i);
    while (!st.empty()) {
      auto j = st.top();
      ans[j] = ans[i];
      st.pop();
    }
  }
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
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