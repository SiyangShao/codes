#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto cal(int n, vector<ll> &a) {
  vector<int> smaller(n, n), larger(n, n);
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty()) {
      if (a[st.top()] > a[i]) {
        smaller[st.top()] = i;
        st.pop();
      } else {
        break;
      }
    }
    st.emplace(i);
  }
  while (!st.empty())
    st.pop();
  for (int i = 0; i < n; ++i) {
    while (!st.empty()) {
      if (a[st.top()] < a[i]) {
        larger[st.top()] = i;
        st.pop();
      } else {
        break;
      }
    }
    st.emplace(i);
  }
  dbg(smaller, larger);
  vector<ll> preSum(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    preSum[i] = preSum[i - 1] + a[i - 1];
  }
  vector<int> dp(n, n);
  for (int i = 0; i + 1 < n; ++i) {
    // should have at least this
    ll nd = preSum[i + 1] + a[i];
    auto it = upper_bound(preSum.begin(), preSum.end(), nd);
    if (it == preSum.end())
      dp[i] = n;
    else {
      int j = (int)(it - preSum.begin()) - 1;
      if (j > i + 1)
        j = max(j, min(larger[i + 1], smaller[i + 1]));
      if (j == n)
        dp[i] = n;
      else
        dp[i] = j - i;
    }
  }
  return dp;
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  auto lef = cal(n, a);
  reverse(a.begin(), a.end());
  auto rig = cal(n, a);
  reverse(rig.begin(), rig.end());
  dbg(lef, rig);
  for (int i = 0; i < n; ++i) {
    int ans = min(lef[i], rig[i]);
    if (ans == n) {
      cout << "-1 ";
    } else {
      cout << ans << " ";
    }
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