#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
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
  double dist() const { return sqrt((double)dist2()); }
  // angle to x−axis in interval [−pi , pi ]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this / dist(); } // makes d i s t ()=1
  P perp() const { return P(-y, x); }       // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated ’a ’ radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream &operator<<(ostream &os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

using ll = __int128;
using P = Point<__int128>;
std::istream &operator>>(std::istream &is, ll &value) {
  std::string s;
  is >> s;
  value = 0;
  bool isNegative = false;
  if (!s.empty() && s[0] == '-') {
    isNegative = true;
    s.erase(0, 1);
  }
  for (char c : s) {
    value = value * 10 + (c - '0');
  }
  if (isNegative) {
    value = -value;
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, ll value) {
  bool isNegative = false;
  if (value < 0) {
    isNegative = true;
    value = -value;
  }
  std::string s;
  while (value > 0) {
    s.push_back('0' + (value % 10));
    value /= 10;
  }
  if (s.empty()) {
    s = "0";
  } else if (isNegative) {
    s.push_back('-');
  }
  std::reverse(s.begin(), s.end());
  os << s;
  return os;
}

bool check(P &s, P &e, P &p, ll r) {
  assert(s != e);
  using pp = Point<__int128>;
  pp s1 = pp(s.x, s.y), e1 = pp(e.x, e.y), p1 = pp(p.x, p.y);
  auto d = (e1 - s1).dist2();
  auto t = min(d, max(__int128(0), (p1 - s1).dot(e1 - s1)));
  auto dd = (p1 - s1) * d - (e1 - s1) * t;
  auto rr = __int128(r);
  return dd.dist2() >= rr * rr * d * d;
}
template <class P> int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }
auto solve() {
  int n;
  cin >> n;
  P p;
  cin >> p.x >> p.y;
  ll r;
  cin >> r;
  vector<P> hull(n);
  for (auto &[x, y] : hull)
    cin >> x >> y;
  ll sum = 0;
  ll ans = 0;
  for (int lef = 0, rig = 0; lef < n; ++lef) {
    // rig go until intersect or at right
    if (rig == lef) {
      sum += hull[rig].cross(hull[(rig + 1) % n]);
      rig = (rig + 1) % n;
    }
    // assert(check(hull[lef], hull[rig], p, r) &&
    //        sideOf(hull[lef], hull[rig], p) == 1);
    // ans = max(ans, sum + hull[rig].cross(hull[lef]));
    auto nxt = (rig + 1) % n;
    while (check(hull[lef], hull[nxt], p, r) &&
           sideOf(hull[lef], hull[nxt], p) == 1 && nxt != lef) {
      sum += hull[rig].cross(hull[nxt]);
      rig = nxt;
      ans = max(ans, sum + hull[rig].cross(hull[lef]));
      nxt = (rig + 1) % n;
    }
    sum -= hull[lef].cross(hull[(lef + 1) % n]);
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
