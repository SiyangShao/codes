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
  int cur = 1, ans = 0;
  for (auto i : a) {
    if (i == cur) {
      cur++;
      ans++;
    }
  }
  ans = n - ans;
  cout << (ans / k) + (ans % k == 0 ? 0 : 1) << "\n";
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
