#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  int res = n % k;
  int ans = 0;
  for (int i = res + k + 1; i + k - 1 <= n; i += k) {
    cout << "? " << i << endl;
    int y;
    cin >> y;
    ans ^= y;
  }
  for (int i = 1; i + k - 1 <= res + k; i += max(res / 2, 1)) {
    cout << "? " << i << endl;
    int y;
    cin >> y;
    ans ^= y;
  }
  cout << "! " << ans << endl;
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