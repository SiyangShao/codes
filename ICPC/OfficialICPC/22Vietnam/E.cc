#include <bits/stdc++.h>
using namespace std;
using ld = long double;
constexpr ld PI = 3.14159265358979323846;
struct DSU {
  vector<int> fa;
  DSU(int n) : fa(n) { iota(fa.begin(), fa.end(), 0); }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    fa[x] = y;
  }
};
struct point {
  ld x, y;
  point() { x = 0, y = 0; }
  point(ld _x, ld _y) {
    x = _x;
    y = _y;
  }
  ld len() { return hypot(x, y); }
  point operator+(const point &p) const { return {x + p.x, y + p.y}; }
  point operator-(const point &p) const { return {x - p.x, y - p.y}; }
  point operator*(ld c) const { return {x * c, y * c}; }
  point operator/(ld c) const { return {x / c, y / c}; }
  ld operator^(const point &p) const { return x * p.y - y * p.x; }
  ld operator*(const point &p) const { return x * p.x + y * p.y; }
};
ld angle(const point &A, const point &O, const point &B) {
  point AO = A - O;
  point BO = B - O;
  return acos(AO * BO / (AO.len() * BO.len()));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<point> p(n);
  for (auto &[x, y] : p) {
    cin >> x >> y;
  }
  ld x = 0, y = 0, c = 0;
  for (int i = 0; i < n; ++i) {
    x += (p[i].x + p[(i + 1) % n].x) *
         (p[i].x * p[(i + 1) % n].y - p[(i + 1) % n].x * p[i].y);
    y += (p[i].y + p[(i + 1) % n].y) *
         (p[i].x * p[(i + 1) % n].y - p[(i + 1) % n].x * p[i].y);
    c += p[i].x * p[(i + 1) % n].y - p[(i + 1) % n].x * p[i].y;
  }
  c /= 2;
  x /= 6 * c;
  y /= 6 * c;
  point C(x, y);
  vector<ld> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = angle(p[i], C, p[(i + 1) % n]) / (2 * PI);
  }
  DSU dsu(n);
  for (int i = 0; i < n; ++i) {
    if (angle(C, p[i], p[(i + 1) % n]) > PI / 2) {
      dsu.merge(i, (i - 1 + n) % n);
    } else if (angle(C, p[(i + 1) % n], p[i]) > PI / 2) {
      dsu.merge(i, (i + 1) % n);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (dsu.find(i) != i) {
      ans[dsu.find(i)] += ans[i];
      ans[i] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << fixed << setprecision(10) << ans[i] << '\n';
  }
}