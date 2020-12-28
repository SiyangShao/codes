#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll r, c;
  cin >> r >> c;
  vector<string> mp(r);
  ll num = 0;
  for (auto &i : mp) {
    cin >> i;
    for (auto &j : i) {
      if (j == '#')
        num++;
    }
  }
  if (min(r, c) > 2) {
    ll ans = 0;
    for (ll i = 1; i + 1 < r; ++i) {
      for (ll j = 1; j + 1 < c; ++j) {
        if (mp[i][j] == '.')
          ans++;
      }
    }
    bool flag = false;
    for (ll i = 1; i + 1 < r; ++i) {
      if (mp[i][0] == '#' || mp[i][c - 1] == '#')
        flag = true;
    }
    for (ll j = 1; j + 1 < c; ++j) {
      if (mp[0][j] == '#' || mp[r - 1][j] == '#')
        flag = true;
    }
    if (!flag) {
      ans++;
    }
    cout << ans << "\n";
  }
  if (r == 1) {
    ll ans = 0;
    for (ll i = 1; i + 1 < c; ++i) {
      if (mp[0][i] == '.')
        ans++;
    }
    cout << ans << "\n";
  } else if (c == 1) {
    ll ans = 0;
    for (ll i = 1; i + 1 < r; ++i) {
      if (mp[i][0] == '.')
        ans++;
    }
    cout << ans << "\n";
  } else if (c == 2) {
    ll ans = 0;
    for (ll i = 1; i + 1 < r; ++i) {
      if (mp[i][0] == '.' && mp[i][1] == '.')
        ans++;
    }
    cout << ans << "\n";
  } else if (r == 2) {
    ll ans = 0;
    for (ll i = 1; i + 1 < c; ++i) {
      if (mp[0][i] == '.' && mp[1][i] == '.')
        ans++;
    }
    cout << ans << "\n";
  }
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