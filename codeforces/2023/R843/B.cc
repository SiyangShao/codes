#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// constexpr ll N = 2e5 + 1;
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> st(n);
  map<int, int> vec;
  vec.clear();
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    st[i].resize(k);
    for (auto &j : st[i]) {
      cin >> j;
      vec[j]++;
    }
  }
  for (auto &i : st) {
    bool flag = true;
    for (auto j : i) {
      if (vec[j] == 1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
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
