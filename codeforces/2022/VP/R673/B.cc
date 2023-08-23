#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll ans = 0;
  for (auto &i : a) {
    cin >> i;
    ans += i;
  }
  if (ans % n != 0) {
    cout << "-1\n";
    return;
  }
  ans /= n;
  vector<tuple<ll, ll, ll>> output;
  for (ll i = 1; i < n; ++i) {
    ll dif = (i + 1) - (a[i] % (i + 1));
    dif %= (i + 1);
    output.emplace_back(0, i, dif);
    a[0] -= dif, a[i] += dif;
    assert(a[0] >= 0);
    dif = a[i] / (i + 1);
    output.emplace_back(i, 0, dif);
    a[0] += dif * (i + 1), a[i] -= dif * (i + 1);
    assert(a[i] == 0);
  }
  for (ll i = 1; i < n; ++i) {
    output.emplace_back(0, i, ans);
  }
  cout << output.size() << "\n";
  for (auto &[i, j, x] : output) {
    cout << i + 1 << " " << j + 1 << " " << x << "\n";
  }
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
