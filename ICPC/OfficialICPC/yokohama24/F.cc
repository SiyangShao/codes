#include <bits/stdc++.h>
using namespace std;
template <class T> int sgn(T x) { return (T(0) < x) - (x < T(0)); }
template <class T> struct Point {
  using P = Point;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(T d) const { return P(x * d, y * d); }
  P operator/(T d) const { return P(x / d, y / d); }
  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt(double(dist2())); }
  double angle() const { return atan2(y, x); }
  P unit() const { return *this / dist(); }
  P perp() const { return P(-y, x); }
  P normal() const { return perp().unit(); }
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream &operator<<(ostream &os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};
using P = Point<double>;
double ccRadius(const P &A, const P &B, const P &C) {
  return (B - A).dist() * (C - B).dist() * (A - C).dist() /
         abs((B - A).cross(C - A)) / 2;
}
P ccCenter(const P &A, const P &B, const P &C) {
  P b = C - A, c = B - A;
  return A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;
}
tuple<int, int, int> check(int x, int y, int z) {
  int a = (x + y) * (x + y) + z * z;
  int b = (x + z) * (x + z) + y * y;
  int c = (y + z) * (y + z) + x * x;
  if (a == min({a, b, c})) {
    return make_tuple(x, y, z);
  } else if (b == min({a, b, c})) {
    return make_tuple(x, z, y);
  } else {
    return make_tuple(y, z, x);
  }
}
auto checkO(P O, int x, int y) {
  if (O.x < 0 || O.x > y || O.y < 0 || O.y > x)
    return false;
  return true;
}
auto sol(int x, int y, int z) {
  P A(-x, -z), B(y + z, x + y), C(-z, x), D(0, x + z), F(0, -x - z),
      G(y + z + y, x), H(y + z, -x - y), I(y + z + y, -x);
  vector<P> v = {A, B, C, D, F, G, H, I};
  double ans = -1;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      for (int k = j + 1; k < v.size(); k++) {
        auto O = ccCenter(v[i], v[j], v[k]);
        if (!checkO(O, x, y))
          continue;
        double r = ccRadius(v[i], v[j], v[k]);
        for (int l = 0; l < v.size(); l++) {
          r = min(r, (O - v[l]).dist());
        }
        ans = max(ans, r);
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int a, b, c;
  cin >> a >> b >> c;
  // cout << x << " " << y << " " << z << "\n";
  auto a1 = sol(a, b, c);
  auto a2 = sol(a, c, b);
  auto b1 = sol(b, a, c);
  auto b2 = sol(b, c, a);
  auto c1 = sol(c, a, b);
  auto c2 = sol(c, b, a);
  auto ans = max({a1, a2, b1, b2, c1, c2});
  // cout << a1 << " " << a2 << " " << b1 << " " << b2 << " " << c1 << " " << c2
  // << "\n";
  assert(ans >= 0);
  cout << setprecision(16) << ans << "\n";
}
