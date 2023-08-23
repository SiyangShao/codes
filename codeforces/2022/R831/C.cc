#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end(), greater<>());
  ll w1 = a.back();
  a.pop_back();
  ll ans = 0;
  for (int i = 0; i + 1 < a.size(); ++i) {
    ans = max(ans, a[i] - a[i + 1] + a[i] - w1);
  }
  a.emplace_back(w1);
  reverse(a.begin(), a.end());
  w1 = a.back();
  a.pop_back();
  for (int i = 0; i + 1 < a.size(); ++i) {
    ans = max(ans, a[i + 1] - a[i] + w1 - a[i]);
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