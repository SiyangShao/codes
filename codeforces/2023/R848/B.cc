#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> p(n), pos(n);
  for (auto &i : p) {
    cin >> i;
    i--;
  }
  for (int i = 0; i < n; ++i) {
    pos[p[i]] = i;
  }
  vector<int> a(m);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  int ans = n * 2;
  for (int i = 0; i + 1 < m; ++i) {
    if (pos[a[i + 1]] < pos[a[i]] || pos[a[i + 1]] - pos[a[i]] > d) {
      ans = 0;
      break;
    }
    if (n - 1 - 0 > d) {
      ans = min(ans, d + 1 - (pos[a[i + 1]] - pos[a[i]]));
    }
    ans = min(ans, pos[a[i + 1]] - pos[a[i]]);
  }
  cout << ans << "\n";
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