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
  vector<ll> c(n);
  for (auto &i : c) {
    cin >> i;
  }
  ll k;
  cin >> k;
  stack<tuple<ll, ll, ll>> st;
  for (int i = 0; i < n; ++i) {
    if (st.empty()) {
      if (k / c[i] == 0)
        continue;
      st.emplace(i, k / c[i], k % c[i]);
    } else {
      ll all = 0;
      while (!st.empty()) {
        auto [j, x, res] = st.top();
        if (c[j] >= c[i]) {
          all += c[j] * x + res;
          st.pop();
          continue;
        } else {
          break;
        }
      }
      if (st.empty()) {
        st.emplace(i, all / c[i], all % c[i]);
      } else {
        auto [j, x, res] = st.top();
        st.pop();
        all += c[j] * x + res;
        // divide all to c[j]
        x = all / c[j];
        res = all % c[j];
        ll can_take = res / (c[i] - c[j]);
        can_take = min(can_take, x);
        if (can_take == x) {
          st.emplace(i, all / c[i], all % c[i]);
        } else {
          res = all - c[j] * (x - can_take) - c[i] * can_take;
          st.emplace(j, x - can_take, 0);
          st.emplace(i, can_take, res);
        }
      }
    }
  }
  vector<ll> ans(n + 1);
  while (!st.empty()) {
    auto [i, x, res] = st.top();
    st.pop();
    ans[0] += x;
    ans[i + 1] -= x;
  }
  ll pre = 0;
  for (int i = 0; i < n; ++i) {
    pre += ans[i];
    cout << pre << " ";
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