#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  unsigned long long ans = a[0];
  for (auto &i : a) {
    ans = ans & i;
  }
  ll cnt = popcount(ans);
  cout << (1LL << cnt) - 1 << "\n";
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