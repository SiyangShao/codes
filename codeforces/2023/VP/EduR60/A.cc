#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  auto mx = *max_element(a.begin(), a.end());
  int len = 1, cur = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == mx && a[i - 1] == mx) {
      cur++;
      len = max(len, cur);
    } else {
      cur = 1;
    }
  }
  cout << len << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}