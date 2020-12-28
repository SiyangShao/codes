#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &i : p)
    cin >> i;
  deque<int> L, R;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    R.clear();
    for (int j = i + 1; j < n; ++j) {
      R.emplace_back(p[j]);
    }
    for (int j = i + 1; j < n; ++j) {
      R.pop_front();
      ll r = R.end() - lower_bound(R.begin(), R.end(), p[j] + (p[j] - p[i]));
      ll l = L.end() - upper_bound(L.begin(), L.end(), -(p[i] - (p[j] - p[i])));
      ans += qpow(2, r) * qpow(2, l) % MOD;
      ans %= MOD;
    }
    L.emplace_front(-p[i]);
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