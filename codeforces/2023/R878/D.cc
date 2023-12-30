#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  function<bool(ll)> check = [&](ll dif) {
    ll x = -1, y = -1, z = -1;
    for (auto i : a) {
      if (x == -1) {
        x = i + dif;
      } else if (x + dif < i) {
        if (y == -1) {
          y = i + dif;
        } else if (y + dif < i) {
          if (z == -1) {
            z = i + dif;
          } else if (z + dif < i) {
            return false;
          }
        }
      }
    }
    return true;
  };
  ll l = 0, r = 1e9;
  ll ans = r;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      r = mid - 1;
      ans = min(ans, mid);
    } else {
      l = mid + 1;
    }
  }
  cout << ans << "\n";
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