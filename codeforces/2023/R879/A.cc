#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int pos = 0, neg = 0;
  for (auto &i : a) {
    cin >> i;
    if (i == 1) {
      pos++;
    } else {
      neg++;
    }
  }
  int cnt = 0;
  if (neg % 2 == 1) {
    cnt++;
    neg--, pos++;
  }
  if (pos >= neg) {
    cout << cnt << "\n";
  } else {
    for (int i = 0; i <= neg; ++i) {
      if (pos + i >= neg - i && (neg - i) % 2 == 0) {
        cout << cnt + i << "\n";
        break;
      }
    }
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