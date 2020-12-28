#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto query(ll i, ll j) {
  i++, j++;
  cout << "? " << i << " " << j << endl;
  ll x;
  cin >> x;
  return x;
}
auto output(ll x, ll y) {
  x++, y++;
  cout << "! " << x << " " << y << endl;
}
auto solve() {
  ll n;
  cin >> n;
  if (n == 2) {
    output(0, 1);
    return;
  }
  ll x = 0, y = 1;
  for (int i = 2; i < n; ++i) {
    ll a = query(x, i), b = query(y, i);
    if (a == b)
      continue;
    if (a > b) {
      y = i;
    } else {
      x = i;
    }
  }
  output(x, y);
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
    ll n;
    cin >> n;
    assert(n == 1);
    cout.flush();
  }
}
