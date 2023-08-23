#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> pre(n + 1, 0);
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = pre[i] ^ a[i];
  }
  ll base = (1 + n) * n / 2;
  const ll mx = (ll)sqrt((1LL << ll(log2(n) + 1)));
  const ll N = 1LL << (ll(log2(n) + 1));
  vector<ll> mp(N, 0);
  mp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    assert(a[i - 1] < N && pre[i] < N);
    for (ll k = 0; k <= mx; ++k) {
      ll tmp = (k * k) ^ pre[i];
      if (tmp < N)
        base -= mp[tmp];
      else
        break;
    }
    mp[pre[i]]++;
  }
  cout << base << "\n";
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
