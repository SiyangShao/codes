#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i128 = __int128;
auto solve() {
  ll A, B;
  cin >> A >> B;
  // T: A / sqrt(1 + t) + t * B minimum
  i128 l = 0, r = i128(A) * i128(A);
  function<ld(i128)> f = [&](auto x) {
    return ld(A) / sqrt((ld)x + 1) + ld(x) * B;
  };
  while (l + 3 < r) {
    // cout<<ld(l)<<" "<<ld(r)<<"\n";
    auto margin = (r - l) / 3;
    auto m1 = l + margin;
    auto m2 = r - margin;
    if (f(m1) < f(m2)) {
      r = m2;
    } else {
      l = m1;
    }
  }
  cout << setprecision(20);
  cout << min(f(l + 2), min(f(l), f(l + 1))) << "\n";
}
auto main() -> int {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}