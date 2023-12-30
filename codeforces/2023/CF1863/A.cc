#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, a, q;
  cin >> n >> a >> q;
  string s;
  cin >> s;
  int mx = a;
  if (a == n) {
    cout << "YES\n";
    return;
  }
  for (auto i : s) {
    if (i == '+') {
      mx++;
      a++;
    } else {
      a--;
    }
    if (a == n) {
      cout << "YES\n";
      return;
    }
  }
  if (mx >= n) {
    cout << "MAYBE\n";
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