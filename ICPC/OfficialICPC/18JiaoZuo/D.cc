#include <bits/stdc++.h>
using namespace std;
using ld = long double;
constexpr ld eps = 1e-8;
const ld PI = acos(-1);
auto solve() {
  int a, b, r, d;
  cin >> a >> b >> r >> d;
  ld x = sqrt((r + a) * (r + a) + b * b);
  ld theta = acos((r + a) * 1.0 / x);
  ld alpha = d * 1.0 * PI / 180.0;
  if (alpha >= theta - eps) {
    cout << setprecision(13) << x - ld(r) << "\n";
  } else {
    // cout<<"-1\n";
    cout << setprecision(13) << x * cos(theta - alpha) - ld(r) << "\n";
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