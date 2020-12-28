#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
auto solve() {
  int n, m;
  cin >> n >> m;
  vector mp(n, vector<int>(m, 0));
  vector status(n + 1, vector<int>(m + 1));
  vector rec(n + 1, vector<int>(m + 1, 0));
  for (auto &i : mp)
    for (auto &j : i)
      cin >> j;
  auto init = [&](int l) {
    rep(i, 0, n) rep(j, 0, m) if (mp[i][j] < l) status[i + 1][j + 1] = 1;
    else status[i + 1][j + 1] = 0;
    rep(i, 1, n + 1) rep(j, 1, m + 1) rec[i][j] =
        status[i][j] + rec[i - 1][j] + rec[i][j - 1] - rec[i - 1][j - 1];
  };
  auto cal = [&](int x1, int y1, int x2, int y2) {
    return rec[x2][y2] - rec[x1 - 1][y2] - rec[x2][y1 - 1] +
           rec[x1 - 1][y1 - 1];
  };
  auto judge = [&](int l) {
    init(l);
    for (int i = 1; i + l - 1 <= n; ++i) {
      for (int j = 1; j + l - 1 <= m; ++j) {
        if (cal(i, j, i + l - 1, j + l - 1) == 0)
          return true;
      }
    }
    return false;
  };
  int l = 1, r = min(n, m);
  int ans = l;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (judge(mid)) {
      ans = max(ans, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
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
