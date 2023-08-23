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
  if (n == 2) {
    cout << "2\n";
    return;
  }
  bool flag = (n % 2 == 0 ? true : false);
  for (int i = 2; i + 1 < n; ++i) {
    if (a[i] != a[i - 2] || a[i + 1] != a[i - 1]) {
      flag = false;
      break;
    }
  }
  if (!flag) {
    cout << n << "\n";
  } else {
    cout << n / 2 + 1 << "\n";
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
