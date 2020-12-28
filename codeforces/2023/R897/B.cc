#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int dif = 0;
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (s[i] == s[j]) {
      continue;
    } else {
      dif++;
    }
  }
  int mx = n / 2 - dif;
  mx *= 2;
  mx += dif;
  mx += (n % 2 == 1 ? 1 : 0);
  for (int i = 0; i <= n; ++i) {
    if (i < dif || i > mx) {
      cout << "0";
    } else {
      int change = i - dif;
      if (change % 2 == 0) {
        cout << "1";
      } else {
        if (n % 2 == 1) {
          cout << "1";
        } else {
          cout << "0";
        }
      }
    }
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