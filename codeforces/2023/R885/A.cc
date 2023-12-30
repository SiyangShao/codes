#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int x, y;
  cin >> x >> y;
  bool flag = (x % 2 == y % 2);
  vector<pair<int, int>> friends(k);
  int cnt = 0;
  for (auto &[a, b] : friends) {
    cin >> a >> b;
    if ((a % 2 == b % 2) == flag) {
      cnt++;
    }
  }
  if (cnt == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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