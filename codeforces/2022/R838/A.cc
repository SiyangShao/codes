#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }
  if (sum % 2 == 0) {
    cout << "0\n";
    return;
  }
  ll ans = 1e9 + 7;
  for (auto i : a) {
    ll flg = i % 2, cur = 0;
    while (flg == i % 2) {
      i /= 2;
      cur++;
    }
    ans = min(ans, cur);
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
