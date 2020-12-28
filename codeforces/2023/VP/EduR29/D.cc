#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, q, m;
  cin >> n >> q >> m;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<tuple<int, int, int>> operation(q);
  for (auto &[t, l, r] : operation) {
    cin >> t >> l >> r;
    l--, r--;
  }
  reverse(operation.begin(), operation.end());
  vector<int> b(m);
  for (auto &i : b) {
    cin >> i;
    i--;
  }
  for (const auto &[t, l, r] : operation) {
    if (t == 1) {
      for (auto &i : b) {
        if (i == l) {
          i = r;
        } else if (i >= l && i <= r) {
          i--;
        }
      }
    } else {
      for (auto &i : b) {
        if (i >= l && i <= r) {
          auto dis = i - l;
          i = r - dis;
        }
      }
    }
  }
  for (auto &i : b) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}
