#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m, h, k;
  cin >> n >> m >> k >> h;
  vector<ll> a(n);
  int cnt = 0;
  for (auto &i : a) {
    cin >> i;
    if (abs(i - h) % k == 0 && abs(i - h) / k < m && i != h) {
      cnt++;
    }
  }
  cout << cnt << "\n";
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