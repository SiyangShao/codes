#include <bits/stdc++.h>
using namespace std;
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
};
using ll = long long;
using P = Point<ll>;
vector<P> convexHull(vector<P> pts) {
  if (pts.size() <= 1)
    return pts;
  sort(pts.begin(), pts.end());
  vector<P> h(pts.size() + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end())) {
    for (P p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0)
        t--;
      h[t++] = p;
    }
  }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}
ll polygonArea2(vector<P> &v) {
  auto a = v.back().cross(v[0]);
  for (int i = 0; i < (int)v.size() - 1; i++) {
    a += v[i].cross(v[i + 1]);
  }
  return abs(a);
}
auto solve() {
  int n;
  cin >> n;
  vector<P> pts(n);
  for (auto &[u, v] : pts)
    cin >> u >> v;
  auto hull = convexHull(pts);
  set<P> outHull;
  for (auto p : hull) {
    outHull.emplace(p);
  }
  vector<P> inside;
  for (auto p : pts) {
    if (outHull.count(p) == 0) {
      inside.emplace_back(p);
    }
  }
  if (inside.empty()) {
    cout << "-1\n";
    return;
  }
  const auto base = polygonArea2(hull);
  ll ans = 0;
  auto insideHull = convexHull(inside);
  int chooseP = 0;
  hull.emplace_back(hull[0]);
  for (int i = 0; i < (int)hull.size() - 1; i++) {
    // edge: i to (i+1) % hull.size
    auto l = hull[i], r = hull[i + 1];
    vector<P> triangle(3);
    triangle[0] = l, triangle[1] = r;
    const auto begin_p = chooseP;
    while (true) {
      auto p = insideHull[chooseP];
      triangle[2] = p;
      auto size = polygonArea2(triangle);
      ans = max(ans, base - size);
      int nxt = (chooseP + 1) % (int)insideHull.size();
      triangle[2] = insideHull[nxt];
      auto size2 = polygonArea2(triangle);
      ans = max(ans, base - size2);
      if (size2 <= size && nxt != begin_p) {
        chooseP = nxt;
      } else {
        break;
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
