#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  function<bool(ll)> check = [&](ll x) {
    multiset<ll> st;
    for (auto &i : a) {
      st.emplace(i);
    }
    for (ll i = x; i >= 1; --i) {
      if (st.empty())
        return false;
      auto pos = st.upper_bound(i);
      if (pos == st.begin())
        return false;
      pos = prev(pos);
      st.erase(pos);
      if (st.empty())
        return true;
      pos = st.begin();
      auto new_begin = *pos + i;
      st.erase(pos);
      st.emplace(new_begin);
    }
    return true;
  };
  for (ll i = 1; i <= n; ++i) {
    if (check(i)) {
      continue;
    } else {
      cout << i - 1 << "\n";
      return;
    }
  }
  cout << n << "\n";
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