#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), num(n + 1);
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    num[a[i]]++;
  }
  ll ans = 0, cur = 0;
  for (int i = 0; i <= n; ++i) {
    cur += num[i];
    if (cur == i && num[i] == 0) {
      ans++;
    }
  }
  cout << ans << "\n";
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