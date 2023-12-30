#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<ll, ll>> pos(n + 1);
  pos[0] = {0, 0};
  for (int i = 1; i <= n; ++i) {
    switch (s[i - 1]) {
    case 'U':
      pos[i] = {pos[i - 1].first, pos[i - 1].second + 1};
      break;
    case 'D':
      pos[i] = {pos[i - 1].first, pos[i - 1].second - 1};
      break;
    case 'L':
      pos[i] = {pos[i - 1].first - 1, pos[i - 1].second};
      break;
    case 'R':
      pos[i] = {pos[i - 1].first + 1, pos[i - 1].second};
      break;
    }
  }
  ll L = 0, R = inf;
  ll ans = R;
  auto check = [&](ll x) {
    ll turn = x / n, res = x % n;
    ll nx = x1 + pos[n].first * turn + pos[res].first;
    ll ny = y1 + pos[n].second * turn + pos[res].second;
    ll dis = abs(x2 - nx) + abs(y2 - ny);
    return dis <= x;
  };
  while (L <= R) {
    ll mid = (L + R) / 2;
    if (check(mid)) {
      R = mid - 1;
      ans = min(ans, mid);
    } else {
      L = mid + 1;
    }
  }
  if (ans >= inf / 2) {
    cout << "-1\n";
  } else {
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