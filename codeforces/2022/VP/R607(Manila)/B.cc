#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll r, c;
  cin >> r >> c;
  vector<string> mp(r);
  ll A = 0, P = 0;
  for (auto &i : mp) {
    cin >> i;
    for (auto &j : i) {
      if (j == 'A')
        A++;
      else
        P++;
    }
  }
  if (A == 0) {
    cout << "MORTAL\n";
    return;
  } else if (P == 0) {
    cout << "0\n";
    return;
  }
  bool flag = false;
  bool tmp = true;
  for (ll i = 0; i < c; ++i) {
    if (mp[0][i] != 'A') {
      tmp = false;
      break;
    }
  }
  flag = flag | tmp;
  tmp = true;
  for (ll i = 0; i < c; ++i) {
    if (mp[r - 1][i] != 'A') {
      tmp = false;
      break;
    }
  }
  flag = flag | tmp;
  tmp = true;
  for (ll i = 0; i < r; ++i) {
    if (mp[i][0] != 'A') {
      tmp = false;
      break;
    }
  }
  flag = flag | tmp;
  tmp = true;
  for (ll i = 0; i < r; ++i) {
    if (mp[i][c - 1] != 'A') {
      tmp = false;
      // cout<<i+1<<" "<<c<<"\n";
      break;
    }
  }
  flag = flag | tmp;
  if (flag) {
    cout << "1\n";
    return;
  }
  for (ll i = 0; i < r; ++i) {
    tmp = true;
    for (ll j = 0; j < c; ++j) {
      if (mp[i][j] != 'A') {
        tmp = false;
        break;
      }
    }
    flag = flag | tmp;
  }
  for (ll i = 0; i < c; ++i) {
    tmp = true;
    for (ll j = 0; j < r; ++j) {
      if (mp[j][i] != 'A') {
        tmp = false;
        break;
      }
    }
    flag = flag | tmp;
  }

  if (flag || mp[0][0] == 'A' || mp[0][c - 1] == 'A' || mp[r - 1][0] == 'A' ||
      mp[r - 1][c - 1] == 'A') {
    cout << "2\n";
    return;
  }
  for (ll i = 0; i < r; ++i) {
    for (ll j = 0; j < c; ++j) {
      if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
        if (mp[i][j] == 'A') {
          flag = true;
        }
      }
    }
  }
  if (flag) {
    cout << "3\n";
    return;
  }
  cout << "4\n";
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