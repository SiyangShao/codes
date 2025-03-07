#include <bits/stdc++.h>
using ll = long long;
using i128 = __int128;
#define int ll
using namespace std;
// Extended Euclidean Algorithm
tuple<int, int, int> extended_gcd(int a, int b) {
  if (b == 0)
    return {a, 1, 0};
  int gcd, x1, y1;
  tie(gcd, x1, y1) = extended_gcd(b, a % b);
  int x = y1;
  int y = x1 - (a / b) * y1;
  return {gcd, x, y};
}

bool find_positive_solution(int a, int b, int c) {
  int gcd, x0, y0;
  tie(gcd, x0, y0) = extended_gcd(a, b);
  i128 x = x0, y = y0;
  i128 cc = c;
  // Check if c is a multiple of gcd
  // Scale x0 and y0 to solve ax + by = c
  x *= cc;
  y *= cc;
  assert(x * a + y * b == cc);
  // cout << x0 << " " << y0 << endl;
  // x0 + b * t > 0, y0 - a * t > 0
  // y0 > a * t
  // t < y0 / a
  i128 t_mx = y / i128(a);
  if (y > 0) {
    if (y - a * t_mx == 0)
      t_mx--;
  } else {
    if (y - a * t_mx <= 0) {
      t_mx--;
    }
  }
  if (x + b * t_mx > 0 && y - a * t_mx > 0)
    return true;
  return false; // No positive solution
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b, n;
    cin >> a >> b >> n;
    if (find_positive_solution(a, b, n)) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}
