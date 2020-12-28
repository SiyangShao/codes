#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (a == n && b == n) {
    cout << "Yes\n";
  } else {
    if (a + b >= n - 1) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
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
