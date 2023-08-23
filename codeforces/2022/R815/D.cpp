#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 32 * (3e5) + 7;
array<array<ll, 2>, N> tr, f;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<ll> dp(n, 1);
  ll cnt = 0;
  function<ll(ll, ll)> ask = [&](ll n, ll k) {
    ll res = 1;
    ll u = 0;
    for (ll i = 31; i >= 0; --i) {
      ll bit = (n >> i) & 1;
      ll rev = tr[u][bit ^ 1];
      res = max(res, f[rev][(k >> i) & 1 ^ 1] + 1);
      if (tr[u][bit] == 0)
        break;
      u = tr[u][bit];
    }
    return res;
  };
  function<void(ll, ll)> insert = [&](ll n, ll id) {
    ll u = 0;
    for (ll i = 31; i >= 0; --i) {
      ll bit = (n >> i) & 1;
      if (!tr[u][bit]) {
        tr[u][bit] = ++cnt;
      }
      u = tr[u][bit];
      f[u][(id >> i) & 1] = max(f[u][(id >> i) & 1], dp[id]);
    }
  };
  for (ll i = 0; i < n; ++i) {
    ll tmp = a[i] ^ i;
    dp[i] = ask(tmp, a[i]);
    insert(tmp, i);
  }
  for (ll i = 0; i <= cnt; ++i) {
    tr[i][0] = tr[i][1] = f[i][0] = f[i][1] = 0;
  }
  cout << *max_element(dp.begin(), dp.end()) << "\n";
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