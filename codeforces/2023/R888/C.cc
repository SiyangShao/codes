#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int cnt = 0;
  int l = -1, r = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == a[0]) {
      cnt++;
    }
    if (cnt == k) {
      l = i;
      break;
    }
  }
  cnt = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == a[n - 1]) {
      cnt++;
    }
    if (cnt == k) {
      r = i;
      break;
    }
  }
  if (a[0] == a[n - 1] && l != -1) {
    cout << "YES\n";
    return;
  }
  if (l != -1 && r != -1 && l < r) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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