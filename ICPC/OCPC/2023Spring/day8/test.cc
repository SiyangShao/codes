#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array dx = {1, 1, -1, -1, 3, 3, -3, -3}, dy = {3, -3, 3, -3, 1, -1, 1, -1};
auto solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> pos;
  vector<int> visx(n + 1, 0), visy(n + 1, 0);
  function<bool(int, int, int)> dfs = [&](int i, int j, int k) {
    if (i < 1 || i > n || j < 1 || j > n)
      return false;
    if (visx[i] || visy[j])
      return false;
    visx[i] = visy[j] = 1;
    if (k == 1 && i == n && j == n) {
      visx[i] = visy[j] = 0;
      return true;
    } else if (k == 1) {
      visx[i] = visy[j] = 0;
      return false;
    }
    for (int stp = 0; stp < 8; ++stp) {
      int x = i + dx[stp], y = j + dy[stp];
      if (dfs(x, y, k - 1)) {
        cout<<x<<" "<<y<<"\n";
        return true;
      }
    }
    visx[i] = visy[j] = 0;
    return false;
  };
  int cnt = 0;
  cout << (dfs(1, 3, n) ? "YES" : "NO\n") << "\n";
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