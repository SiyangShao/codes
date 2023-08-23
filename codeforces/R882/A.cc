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
  ll sum = 0;
  vector<int> top;
  for (int i = 1; i < n; ++i) {
    sum += abs(a[i] - a[i - 1]);
    top.emplace_back(abs(a[i] - a[i - 1]));
  }
  ranges::sort(top, greater<>());
  for (int i = 0; i < k - 1; ++i) {
    sum -= top[i];
  }
  cout << sum << "\n";
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