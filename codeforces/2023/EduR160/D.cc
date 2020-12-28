#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using i64 = long long;
constexpr i64 MOD = 998'244'353;
struct ll {
  i64 val;
  ll() { val = 0; }
  ll(i64 x) { val = x; }
  ll(int x) { val = x; }
  ll operator+(const ll &y) {
    ll newOp;
    newOp.val = this->val + y.val;
    if (newOp.val >= MOD)
      newOp.val -= MOD;
    return newOp;
  }
  ll operator-(const ll &y) {
    ll newOp;
    newOp.val = this->val - y.val;
    if (newOp.val < 0)
      newOp.val += MOD;
    return newOp;
  }
  ll &operator+=(const ll &y) {
    val += y.val;
    if (val >= MOD)
      val -= MOD;
    return *this;
  }
  ll &operator-=(const ll &y) {
    val -= y.val;
    if (val < 0)
      val += MOD;
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &os, const ll &x) {
    os << x.val;
    return os;
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<ll> dp(n + 1), pre(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  stack<int> st;
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    while (!st.empty() and a[i] < a[st.top()]) {
      sum -= dp[st.top()];
      st.pop();
    }
    if (st.empty()) {
      dp[i] = pre[i - 1] + 1;
    } else {
      dp[i] = pre[i - 1] - pre[st.top()] + sum;
    }
    st.emplace(i);
    sum += dp[i];
    pre[i] = pre[i - 1] + dp[i];
  }
  cout << sum << "\n";
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