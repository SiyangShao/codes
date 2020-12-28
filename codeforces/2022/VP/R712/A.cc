#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll x = 0;
  for (auto &i : s) {
    x += i - '0';
  }
  if (s[0] == '0' || s[n - 1] == '0' || x % 2 == 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  string A(n, '.'), B(n, '.');
  ll num = 0;
  for (ll i = 0; i < n; ++i) {
    if (num < x / 2 && s[i] == '1') {
      A[i] = B[i] = '(';
      num++;
    } else if (num >= x / 2 && num < x && s[i] == '1') {
      A[i] = B[i] = ')';
      num++;
    }
  }
  bool flag = true;
  for (ll i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (flag) {
        A[i] = '(';
        B[i] = ')';
      } else {
        A[i] = ')';
        B[i] = '(';
      }
      flag = !flag;
    }
  }
  cout << A << "\n" << B << "\n";
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