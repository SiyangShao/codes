#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, all_k;
  cin >> n >> all_k;
  vector<vector<ll>> E(n);
  vector<ll> s(n);
  for (ll i = 1; i < n; ++i) {
    ll u;
    cin >> u;
    u--;
    E[u].emplace_back(i);
  }
  for (auto &i : s) {
    cin >> i;
  }
  map<pair<ll, ll>, ll> mp;
  function<void(ll, ll)> dfs = [&](ll u, ll k) {
    if (E[u].empty()) {
      mp[{u, k}] = s[u] * k;
      mp[{u, k + 1}] = s[u] * (k + 1);
      return;
    }
    ll average = k / ll(E[u].size());
    // at least, every point has average
    ll bs = 0;
    vector<ll> tmp;
    for (auto v : E[u]) {
      dfs(v, average);
      bs += mp[{v, average}];
      tmp.emplace_back(mp[{v, average + 1}] - mp[{v, average}]);
    }
    // get k answer
    sort(tmp.begin(), tmp.end(), greater<>());
    for (ll i = 0; i < k % ll(E[u].size()); ++i) {
      bs += tmp[i];
    }
    mp[{u, k}] = bs + s[u] * k;
    bs += tmp[k % ll(E[u].size())];
    mp[{u, k + 1}] = bs + s[u] * (k + 1);
  };
  dfs(0, all_k);
  cout << mp[{0, all_k}] << "\n";
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