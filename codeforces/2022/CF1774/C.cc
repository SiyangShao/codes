#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cont = 1;
  char prev = '2';
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == prev) {
      cont++;
    } else {
      cont = 1;
      prev = s[i];
    }
    cout << (i + 2 - cont) << " ";
  }
  cout << "\n";
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