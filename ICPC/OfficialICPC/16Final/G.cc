#include <algorithm>
#include <iostream>
#include <vector>

using LL = long long;

struct Oil {
  int xl, xr, y;

  Oil(int xl, int xr, int y) : xl(xl), xr(xr), y(y) {
    if (this->xl > this->xr) {
      std::swap(this->xl, this->xr);
    }
  }

  int get_weight() const { return xr - xl; }
};

struct Point {
  int x, y;

  Point(int x, int y) : x(x), y(y) {}

  friend bool operator<(const Point &a, const Point &b) {
    bool greater = true;
    if (b.y < 0) {
      greater = !greater;
    }
    if (a.y < 0) {
      greater = !greater;
    }
    if (greater) {
      return (LL)a.x * b.y > (LL)a.y * b.x;
    } else {
      return (LL)a.x * b.y < (LL)a.y * b.x;
    }
  }

  friend bool operator>(const Point &a, const Point &b) { return b < a; }

  friend Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
  }
};

struct WeightedPoint {
  Point p;
  int w;

  WeightedPoint(int x, int y, int w) : p(x, y), w(w) {}

  WeightedPoint(const Point &a, int w) : p(a.x, a.y), w(w) {}

  friend bool operator<(const WeightedPoint &a, const WeightedPoint &b) {
    return a.p < b.p;
  }
};

int n;
std::vector<Oil> oils;

std::pair<WeightedPoint, WeightedPoint> get_point(const Oil &oil,
                                                  const Point &p) {
  Point l = Point(oil.xl, oil.y) - p;
  Point r = Point(oil.xr, oil.y) - p;
  if (l > r) {
    std::swap(l, r);
  }
  return {WeightedPoint(l, oil.get_weight()),
          WeightedPoint(r, -oil.get_weight())};
}

LL get_ans(const Point &p) {
  std::vector<WeightedPoint> points;
  for (int i = 0; i < n; ++i) {
    if (oils[i].y != p.y) {
      auto [l, r] = get_point(oils[i], p);
      points.push_back(l);
      points.push_back(r);
    }
  }
  std::sort(points.begin(), points.end());
  LL ans = 0;
  LL now_ans = 0;
  for (const auto &point : points) {
    now_ans += point.w;
    ans = std::max(ans, now_ans);
  }
  return ans;
}

LL solve() {
  LL ans = 0;
  for (int i = 0; i < n; ++i) {
    LL now_ans = std::max(get_ans(Point(oils[i].xl, oils[i].y)),
                          get_ans(Point(oils[i].xr, oils[i].y))) +
                 oils[i].get_weight();
    //        std::cout << i << ' ' << now_ans << ' ' << oils[i].get_weight() <<
    //        std::endl;
    ans = std::max(ans, now_ans);
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  oils.reserve(n);
  for (int i = 1; i <= n; ++i) {
    int xl, xr, y;
    std::cin >> xl >> xr >> y;
    oils.emplace_back(xl, xr, y);
  }
  std::cout << solve() << '\n';
  return 0;
}
