#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll p = 1e9 + 7, sz = 500000;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> h(n), vis(n, 0);
  for (auto &i : h) {
    cin >> i;
    i--;
  }
  ll mx = n - 1;
  vector<ll> critical;
  for (ll i = n - 1; i >= 0; --i) {
    if (h[i] == mx) {
      critical.emplace_back(i);
      vis[h[i]] = 1;
      while (i >= 0 && vis[mx]) {
        mx--;
      }
    }
    vis[h[i]] = 1;
  }
  reverse(critical.begin(), critical.end());
  ll bs = 1;
  for (ll i = 1; i < critical.size(); ++i) {
    ll num = critical[i] - critical[i - 1] + 1;
    assert(num >= 0);
    bs = bs * num % p;
  }
  cout << bs << "\n";
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