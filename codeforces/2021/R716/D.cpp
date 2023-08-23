#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 3e5 + 7;
array<vector<ll>, N> pos;
auto solve() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (ll i = 0; i < n; ++i) {
    pos[a[i]].emplace_back(i + 1);
  }
  while (q--) {
    ll l, r;
    cin >> l >> r;
    default_random_engine e(time(nullptr));
    uniform_int_distribution<ll> u(l, r);
    ll ans = 1;
    for (ll i = 0; i < 40; ++i) {
      auto val = a[u(e) - 1];
      if (pos[val].empty())
        continue;
      auto &&vec = pos[val];
      ll cnt = upper_bound(vec.begin(), vec.end(), r) -
               lower_bound(vec.begin(), vec.end(), l);
      ans = max(ans, cnt * 2 - (r - l + 1));
      if (cnt > (r - l + 1) / 2)
        break;
    }
    cout << ans << "\n";
  }
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