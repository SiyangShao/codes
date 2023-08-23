#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  n *= 2;
  vector<int> w(n);
  for (auto &i : w) {
    cin >> i;
  }
  sort(w.begin(), w.end());
  ll ans = 1e9 + 7;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ll prev = -1, cur = -1, cnt = 0;
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j)
          continue;
        if (prev == -1) {
          prev = w[k];
        } else {
          assert(cur == -1 && prev != -1);
          cur = w[k];
          cnt += cur - prev;
          prev = -1, cur = -1;
        }
      }
      // cout << cnt << "\n";
      ans = min(ans, cnt);
    }
  }
  cout << ans << "\n";
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
