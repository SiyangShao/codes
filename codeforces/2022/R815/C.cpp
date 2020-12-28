#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array dx = {-1, 0, 1, -1, 1, -1, 0, 1};
array dy = {-1, -1, -1, 0, 0, 1, 1, 1};
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<string> mp(n);
  for (auto &i : mp) {
    cin >> i;
  }
  ll cnt = 0;
  ll flag1 = 0, flag2 = 0;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      if (mp[i][j] == '1') {
        cnt++;
      } else {
        flag1 = 1;
        for (ll k = 0; k < 8; ++k) {
          ll nx = i + dx[k], ny = j + dy[k];
          if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (mp[nx][ny] == '0') {
              flag2 = 1;
            }
          }
        }
      }
    }
  }
  if (flag2) {
    cout << cnt << "\n";
  } else if (flag1) {
    cout << cnt - 1 << "\n";
  } else {
    cout << cnt - 2 << "\n";
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