#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> vec;
  for (int i = 0; i < n / 2; ++i) {
    if (s[i] != s[n - i - 1]) {
      vec.emplace_back(i);
    }
  }
  for (int i = 1; i < (int)vec.size(); ++i) {
    if (vec[i] - vec[i - 1] != 1) {
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