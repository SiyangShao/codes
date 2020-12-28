#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll l = 0, r = 1e14;
  function<bool(ll)> judge = [&](ll mid) {
    ll res = 0;
    for (auto &i : a) {
      res += min(mid, i);
    }
    return res >= mid * m;
  };
  ll ans = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (judge(mid)) {
      ans = max(ans, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
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