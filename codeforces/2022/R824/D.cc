#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> card(n, vector<ll>(k));
  for (auto &i : card) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  map<vector<ll>, ll> mp;
  auto cal = [&](vector<ll> &i, vector<ll> &j) {
    vector<ll> tmp(k);
    for (ll x = 0; x < k; ++x) {
      if (i[x] == j[x]) {
        tmp[x] = i[x];
      } else {
        tmp[x] = 3 - i[x] - j[x];
      }
    }
    return tmp;
  };
  for (ll i = 0; i < n; ++i) {
    for (ll j = i + 1; j < n; ++j) {
      mp[cal(card[i], card[j])]++;
    }
  }
  ll ans = 0;
  for (auto &i : card) {
    ll cnt = mp[i];
    if (cnt > 1) {
      ans += cnt * (cnt - 1) / 2;
    }
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