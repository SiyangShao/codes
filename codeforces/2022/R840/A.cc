#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> bs(32);
  for (auto &i : a) {
    cin >> i;
    int cnt = 0;
    while (i) {
      if (i & 1) {
        bs[cnt]++;
      }
      cnt++;
      i >>= 1;
    }
  }
  ll ans = 0, cnt = 1;
  for (int i = 0; i < 32; ++i) {
    if (bs[i] > 0 && bs[i] < n) {
      ans += cnt;
    }
    cnt *= 2;
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