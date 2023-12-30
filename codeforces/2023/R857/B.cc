#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (auto &[x, y] : a)
    cin >> x >> y;
  sort(a.begin(), a.end());
  multiset<ll> st;
  set<ll> has;
  for (auto &[x, y] : a) {
    st.emplace(y);
  }
  ll ans = inf;
  dbg(a);
  function<pair<ll, ll>(ll)> get = [&](ll x) {
    auto it = has.lower_bound(x);
    ll l = inf, r = inf;
    if (it != has.begin()) {
      l = *prev(it);
    }
    if (it != has.end()) {
      r = *it;
    }
    return pair<ll, ll>{l, r};
  };
  for (int i = 0; i + 1 < n; ++i) {
    ans = min(ans, abs(a[i].second - a[n - 1].first));
  }
  for (auto &[x, y] : a) {
    st.erase(st.find(y));
    ll k = 0;
    if (!st.empty()) {
      k = *prev(st.end());
    } else {
      break;
    }
    auto [l, r] = get(x);
    if (k >= x) {
      ans = min(ans, k - x);
    } else {
      ans = min(ans, x - k);
      if (l > k)
        ans = min(ans, abs(l - x));
      if (r > k)
        ans = min(ans, abs(r - x));
      auto kkk = has.lower_bound(k);
      if (kkk != has.end()) {
        ans = min(ans, abs(*kkk - x));
      }
      if (!has.empty()) {
        ans = min(ans, abs(*prev(has.end()) - x));
      }
    }
    has.emplace(y);
  }
  cout << ans << "\n";
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
