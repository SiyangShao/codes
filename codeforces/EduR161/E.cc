#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto getVal(ll x) {
  ll len = 1;
  while (true) {
    if ((1LL << len) - 1 > x) {
      len--;
      break;
    }
    len++;
  }
  assert(len >= 1);
  return len;
}
auto getVal2(ll x) {
  ll len = 0;
  while (true) {
    if ((1LL << len) > x) {
      len--;
      break;
    }
    len++;
  }
  return len;
}
auto check2(ll x, vector<ll> &ans, ll cur) {
  if (x == 0)
    return;
  ll len = getVal2(x);
  dbg(len);
  x -= (1LL << len);
  auto pos = ans.end() - (len);
  ans.insert(pos, cur);
  dbg(ans, x);
  check2(x, ans, cur - 1);
}
auto check(ll x, vector<ll> &ans, ll cur = 1e9) {
  if (x == 0)
    return;
  ll len = getVal(x);
  dbg(len);
  x -= (1LL << len) - 1;
  for (ll i = cur - len + 1; i <= cur; ++i) {
    ans.emplace_back(i);
  }
  dbg(ans, x);
  check2(x, ans, cur - len);
}
auto solve() {
  ll x;
  cin >> x;
  vector<ll> ans;
  check(x - 1, ans);
  cout << ans.size() << "\n";
  dbg(ans.size());
  assert(ans.size() <= 200);
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