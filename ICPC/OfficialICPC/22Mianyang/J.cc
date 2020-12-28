#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
auto solve() {
  ll n, A, B, C;
  cin >> n >> A >> B >> C;
  vector<ll> tmp = {A, B, C};
  sort(tmp.begin(), tmp.end());
  A = tmp[0], B = tmp[1], C = tmp[2];
  ld ave = (ld)n * (A + B + C) / 3.0;
  // Ax+By+Cz
  // x+y+z == n
  vector<pair<ld, array<ll, 3>>> vec;
  for (ll x = 0; x <= n; ++x) {
    ll l = 0, r = n - x;
    ll y = 0, z = 0;
    function<bool(ll)> check = [&](ll mid) {
      y = n - x - mid;
      assert(y >= 0);
      return x * A + y * B + mid * C <= ave;
    };
    while (l <= r) {
      ll mid = (l + r) / 2;
      if (check(mid)) {
        l = mid + 1;
        z = max(z, mid);
      } else {
        r = mid - 1;
      }
    }
    y = n - x - z;
    if (y > 0 && abs(x * A + y * B + z * C - ave) >
                     abs(x * A + (y - 1) * B + (z + 1) * C - ave)) {
      y--, z++;
    }
    vec.emplace_back(abs(x * A + y * B + z * C - ave), array{x, y, z});
  }
  sort(vec.begin(), vec.end());
  // for (auto &[_, arr] : vec) {
  //   cout << _ << " ";
  //   cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
  // }
  int x1, x2;
  auto &&cur = vec[0];
  for (int i = 0; i < cur.second[0]; ++i) {
    cout << A << endl;
    cin >> x1 >> x2;
  }
  for (int i = 0; i < cur.second[1]; ++i) {
    cout << B << endl;
    cin >> x1 >> x2;
  }
  for (int i = 0; i < cur.second[2]; ++i) {
    cout << C << endl;
    cin >> x1 >> x2;
  }
}
auto main() -> int {
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}