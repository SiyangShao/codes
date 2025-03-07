#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<ll, ll> sol(ll l, ll r) {
  ll lef = -1, rig = -1;
  for (ll i = l; i <= l + 30 && i <= r; i++) {
    for (ll j = r; j >= r - 30 && j >= l && j >= i; j--) {
      if (__gcd(i, j) == 1) {
        if (j - i > rig - lef) {
          lef = i;
          rig = j;
        } else if (j - i == rig - lef) {
          if (i < lef || lef == -1) {
            lef = i;
            rig = j;
          }
        }
      }
    }
  }
  return {lef, rig};
}
auto solve() {
  ll l, r, G;
  cin >> l >> r >> G;
  l = (l + G - 1) / G * G;
  r = r / G * G;
  if (l > r) {
    cout << "-1 -1\n";
    return;
  }
  auto ans = sol(l / G, r / G);
  if (ans.first == -1) {
    cout << "-1 -1\n";
    return;
  }
  cout << ans.first * G << " " << ans.second * G << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
