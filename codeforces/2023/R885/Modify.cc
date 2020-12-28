#include <algorithm>
#include <bits/ranges_algo.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
  while (true) {
    if (*ranges::max_element(a) == *ranges::min_element(a) &&
        *ranges::max_element(a) == 0) {
      break;
    }
    for (int i = 0; i < n; ++i) {
      c[i] = abs(a[i] - b[i]);
    }
    for (auto i : c) {
      cout << i << " ";
    }
    cout << "\n";
    swap(a, b);
    swap(b, c);
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