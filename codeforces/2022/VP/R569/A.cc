#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto dfs(ll n) {
  if (n == 1) {
    return 1LL;
  }
  return dfs(n - 1) + (n - 1) * 4;
}
auto solve() {
  ll n;
  cin >> n;
  cout << dfs(n) << "\n";
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