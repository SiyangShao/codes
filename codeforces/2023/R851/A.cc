#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int num = 0;
  for (auto &i : a) {
    cin >> i;
    if (i == 2)
      num++;
  }
  if (num % 2 == 1) {
    cout << "-1\n";
    return;
  }
  num /= 2;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 2)
      cnt++;
    if (cnt == num) {
      cout << i + 1 << "\n";
      return;
    }
  }
  assert(false);
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