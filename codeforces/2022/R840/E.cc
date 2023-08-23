#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll NN = 2e5 + 1;
array<ll, NN> mp;
auto solve() {
  fill(mp.begin(), mp.end(), -1);
  ll n;
  cin >> n;
  if (n == 0) {
    cout << "0 0\n";
    return;
  }
  // for a component has x point, it's contribution is x * (x-1) / 2
  ll N = (ll)sqrt(n * 2) + 1LL;
  vector<ll> p(N + 1);
  for (ll i = 1; i <= N; ++i) {
    p[i] = i * (i - 1) / 2;
  }
  constexpr ll INF = 1e16;
  function<ll(ll)> dfs = [&](ll x) {
    if (mp[x] != -1)
      return mp[x];
    if (x == 0)
      return 0LL;
    ll it = prev(upper_bound(p.begin(), p.end(), x)) - p.begin();
    ll ans = INF;
    for (ll i = it; i >= 2; --i) {
      ll mx = x / p[i];
      ll res = x - mx * p[i];
      ans = min(ans, mx * i + dfs(res));
    }
    return mp[x] = ans;
  };
  ll ans = dfs(n);
  cout << ans << " " << ans * (ans - 1) / 2 - n << "\n";
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