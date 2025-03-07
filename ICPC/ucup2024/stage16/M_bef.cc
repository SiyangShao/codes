
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;
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
  T cross(P p) const { return x * p.x + y * p.y; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  P unit() const { return *this / dist(); }
  double dist() const { return sqrt((double)dist2()); }
  double angle() const { return atan2(y, x); }
  P perp() const { return P(-y, x); }
  friend ostream &operator<<(ostream &os, P p) {
    return os << '(' << p.x << ',' << p.y << ')';
  }
};
template <class P>
vector<pair<P, P>> tangents(P c1, double r1, P c2, double r2) {
  P d = c2 - c1;
  double dr = r1 - r2, d2 = d.dist2(), h2 = d2 - dr * dr;
  if (d2 == 0 || h2 < 0)
    return {};
  vector<pair<P, P>> out;
  for (double sign : {-1, 1}) {
    P v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;
    out.emplace_back(c1 + v * r1, c2 + v * r2);
  }
  if (h2 == 0)
    out.pop_back();
  return out;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, x0, y0, d, t;
  cin >> n >> x0 >> y0 >> d >> t;
  using P = Point<double>;
  P org(x0, y0);
  P c(0, 0);
  P dif = org - c;
  dif = dif.perp();
  P c1 = c + dif.unit() * d, c2 = c - dif.unit() * d;
  // cerr << "c1 c2 " << c1 << " " << c2 << endl;
  // time range after c1 enter and before c2 leave
  vector<P> poly(n);
  auto cal = [&](P p1, P p2) {
    auto e1 = p1 - c;
    auto e2 = p2 - c;
    // angle between e1 and e2
    double angle = e2.angle() - e1.angle();
    if (angle < 0) {
      angle += 2 * M_PI;
    }
    return angle;
  };
  auto ang = [&](P p1, P p2, P p3) {
    // angle p1p2p3
    auto e1 = p1 - p2;
    auto e2 = p3 - p2;
    double angle = e2.angle() - e1.angle();
    if (angle < 0) {
      angle = -angle;
    }
    if (angle > M_PI) {
      return 2 * M_PI - angle;
    }
    return angle;
  };
  vector<pair<double, double>> possible_ranges;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    poly[i] = P(x, y);
    auto res = tangents(c, d, poly[i], 0);
    // cout << res[0].first << " " << res[1].first << endl;
    // before c2 leave res0, after c1 enter res1
    // calculate the degree c1 enter res1
    auto begin = cal(c1, res[1].first);
    auto angle = ang(res[1].first, poly[i], res[0].first);
    auto end = begin + angle;
    if (end >= 2 * M_PI) {
      end -= 2 * M_PI;
    }
    // cerr << begin << " " << end << " " << angle << endl;
    if (begin < end) {
      possible_ranges.emplace_back(begin, end);
    } else {
      possible_ranges.emplace_back(begin, 2 * M_PI);
      possible_ranges.emplace_back(0, end);
    }
  }
  // merge possible ranges
  sort(possible_ranges.begin(), possible_ranges.end());
  vector<pair<double, double>> merged_ranges;
  {
    auto [l, r] = possible_ranges[0];
    for (int i = 1; i < (int)possible_ranges.size(); i++) {
      if (possible_ranges[i].first <= r) {
        r = max(r, possible_ranges[i].second);
      } else {
        merged_ranges.emplace_back(l, r);
        l = possible_ranges[i].first;
        r = possible_ranges[i].second;
      }
    }
    merged_ranges.emplace_back(l, r);
  }
  double base = 0;
  for (auto [l, r] : merged_ranges) {
    base += r - l;
    // cerr << "l, r: " << l << " " << r << "\n";
  }
  double rotate_base = (double)t / (2 * M_PI);
  int rotate_base_int = floor(rotate_base);
  double ans = base * rotate_base_int;
  double res = (double)t - (double)rotate_base_int * 2 * M_PI;
  // 0 - res
  for (auto [l, r] : merged_ranges) {
    if (res > r) {
      ans += r - l;
    } else {
      ans += max(0.0, res - l);
      break;
    }
  }
  cout << fixed << setprecision(12) << ans << "\n";
}
