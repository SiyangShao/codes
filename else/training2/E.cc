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
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  stack<ll> st;
  vector<ll> miL(n, 1), miR(n, 1), mxL(n, 1), mxR(n, 1);
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[i] < a[st.top()]) {
      st.pop();
    }
    if (st.empty()) {
      miL[i] += i;
    } else {
      miL[i] += i - st.top() - 1;
    }
    st.emplace(i);
  }
  while (!st.empty())
    st.pop();
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && a[i] <= a[st.top()]) {
      st.pop();
    }
    if (st.empty()) {
      miR[i] += n - 1 - i;
    } else {
      miR[i] += st.top() - i - 1;
    }
    st.emplace(i);
  }
  while (!st.empty())
    st.pop();
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[i] > a[st.top()]) {
      st.pop();
    }
    if (st.empty()) {
      mxL[i] += i;
    } else {
      mxL[i] += i - st.top() - 1;
    }
    st.emplace(i);
  }
  while (!st.empty())
    st.pop();
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && a[i] >= a[st.top()]) {
      st.pop();
    }
    if (st.empty()) {
      mxR[i] += n - 1 - i;
    } else {
      mxR[i] += st.top() - i - 1;
    }
    st.emplace(i);
  }
  dbg(miL, miR, mxL, mxR);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll miLen = miR[i] * miL[i];
    ll mxLen = mxL[i] * mxR[i];
    ll realLen = mxLen - miLen;
    ans += realLen * a[i];
  }
  cout << ans << "\n";
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