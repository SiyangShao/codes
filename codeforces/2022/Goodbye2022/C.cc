#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] == a[j]) {
        cout << "NO\n";
        return;
      }
    }
  }
  for (ll p = 2; p <= n; ++p) {
    vector<int> num(p, 0);
    for (auto i : a) {
      num[i % p]++;
    }
    if (*min_element(num.begin(), num.end()) >= 2) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
