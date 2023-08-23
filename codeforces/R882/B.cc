#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int and_sum = a[0];
  for (int i = 0; i < n; ++i) {
    and_sum &= a[i];
  }
  if (and_sum != 0) {
    cout << "1\n";
    return;
  }
  int cnt = 0;
  and_sum = -1;
  for (int i = 0; i < n; ++i) {
    if (and_sum == -1) {
      and_sum = a[i];
    } else {
      and_sum &= a[i];
    }
    if (and_sum == 0) {
      ++cnt;
      and_sum = -1;
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