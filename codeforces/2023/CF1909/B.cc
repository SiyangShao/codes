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
  for (auto &i : a) {
    cin >> i;
  }
  ranges::sort(a);
  {
    set<ll> st;
    for (auto i : a) {
      st.emplace(i);
    }
    if ((int)st.size() == 2) {
      cout << ll(1e18) << "\n";
      return;
    }
  }
  {
    // case 1: a[0]
    auto b = a;
    set<ll> st;
    for (auto &i : b) {
      i %= a[0];
      st.emplace(i);
    }
    if ((int)st.size() == 2) {
      cout << a[0] << "\n";
      return;
    }
  }
  function<bool(ll)> check = [&](ll x) {
    set<ll> st;
    for (auto i : a) {
      st.emplace(i % x);
    }
    return (int)st.size() == 2;
  };
  for (ll i = 2; i < a.back(); i *= 2) {
    if (check(i)) {
      cout << i << "\n";
      return;
    }
  }
  assert(false);
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