#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  int cnt = 1;
  for (auto &i : a) {
    cin >> i;
    i -= cnt++;
  }
  if (a[0] != 0) {
    cout << "1\n";
    return;
  }
  ll cur = 1;
  for (int i = 0; i < k; ++i) {
    ll num = (ll)(lower_bound(a.begin(), a.end(), cur) - a.begin());
    cur += num;
  }
  cout << cur << "\n";
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
