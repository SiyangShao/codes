#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr ld eps = 1e-8;
auto solve() {
  ll B, R, D, S;
  cin >> B >> R >> D >> S;
  if (R == 0 && D != 0) {
    cout << "gua!\n";
    return;
  }
  ll cnt = R * S / 60;
  cnt++;
  if (cnt * B < D) {
    cout << "gua!\n";
    return;
  }
  cout << "ok\n";
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