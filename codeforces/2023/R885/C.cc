#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cal(int x, int y) {
  if (x == 0)
    return 0;
  return cal(y, abs(y - x)) + 1;
}
int check_even(int x, int y) {
  if (x == 0 && y == 0)
    return -1;
  if (x == 0) {
    return 0;
  } else if (y == 0) {
    return 1;
  }
  if (x < y) {
    // int dif = y / (2 * x);
    int res = y % (2 * x);
    // x, res, res - x
    return cal(x, res) % 3;
  } else {
    // int dif = x / (2 * y);
    int res = x % (2 * y);
    return cal(res, y) % 3;
  }
}
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  vector<int> flag(3);
  for (int i = 0; i < n; ++i) {
    c[i] = check_even(a[i], b[i]);
    if (c[i] == -1)
      continue;
    flag[c[i]] = 1;
  }
  if (accumulate(flag.begin(), flag.end(), 0) <= 1) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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