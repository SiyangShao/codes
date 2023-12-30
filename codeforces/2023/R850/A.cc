#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  ranges::sort(a);
  ll num = 0;
  int cur = 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == cur) {
      cur++;
    } else if (a[i] > cur) {
      num += a[i] - cur;
      cur++;
    }
  }
  cout << num << "\n";
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
