#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), pos(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  for (ll i = 0; i < n; ++i) {
    pos[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    assert(pos[i] < n);
    cout << b[pos[i]] - a[i] << " ";
  }
  cout << "\n";
  ll flg = 0;
  for (ll i = 0; i < n; ++i) {
    flg = max(flg, i);
    while (flg + 1 < n && pos[flg + 1] <= flg) {
      flg++;
    }
    flg = min(flg, n - 1);
    cout << b[flg] - a[i] << " ";
  }
  cout << "\n";
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