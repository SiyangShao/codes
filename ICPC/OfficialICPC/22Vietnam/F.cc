#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, x0, y0, a, b;
  cin >> n >> x0 >> y0 >> a >> b;
  cout << fixed << setprecision(8) << n * sqrtl(a * a + b * b) / 2.0 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}