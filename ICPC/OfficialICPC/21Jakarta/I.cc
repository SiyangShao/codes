#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using ld = long double;
struct Point {
  using P = Point;
  ld x, y;
  Point(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  [[nodiscard]] ld dist2() const { return x * x + y * y; }
  P operator+(P p) const { return {x + p.x, y + p.y}; }
  P operator-(P p) const { return {x - p.x, y - p.y}; }
};
using P = Point;
constexpr ld inf = 1e17;
ld cloest(vector<P> v) {
  set<P> S;
  sort(v.begin(), v.end(), [&](P a, P b) { return a.y < b.y; });
  pair<ld, pair<P, P>> ret(inf, {P(), P()});
  int j = 0;
  for (auto p : v) {
    P d(1 + sqrt(ret.first), 0);
    constexpr ld eps = 1e-9;
    while (v[j].y <= p.y - d.x + eps)
      S.erase(v[j++]);
    auto lo = S.lower_bound(p - d - eps), hi = S.upper_bound(p + d + eps);
    for (; lo != hi; ++lo) {
      ret = min(ret, {(*lo - p).dist2(), {*lo, p}});
    }
    S.insert(p);
  }
  return sqrt(ret.first);
}
auto solve() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> p(n);
  map<int, vector<pair<int, int>>> mp;
  for (auto &[r, theta, t] : p) {
    cin >> r >> theta >> t;
    mp[t].emplace_back(r, theta);
  }
  set<int> st;
  int dis_dif = 1e9;
  for (auto &[k, v] : mp) {
    for (auto [r, theta] : v) {
      auto it = st.lower_bound(r);
      if (it != st.end())
        dis_dif = min(dis_dif, *it - r);
      if (it != st.begin()) {
        it = prev(it);
        dis_dif = min(dis_dif, r - *it);
      }
    }
    for (auto [r, theta] : v) {
      st.emplace(r);
    }
  }
  // cout << dis_dif << "\n";
  ld dis = dis_dif;
  function<ld(vector<pair<int, int>> &)> sol = [&](vector<pair<int, int>> &v) {
    if ((int)v.size() <= 1) {
      return ld(1e9);
    }
    vector<Point> vec(v.size());
    for (int i = 0; i < (int)v.size(); ++i) {
      ld r = v[i].first;
      ld theta = v[i].second;
#define M_PI 3.14159265358979323846
      theta = theta / 180000 * M_PI;
      vec[i] = Point(r * cos(theta), r * sin(theta));
    }
    return cloest(vec);
  };
  for (auto &[k, v] : mp) {
    dis = min(dis, sol(v));
  }
  cout << fixed << setprecision(10) << dis << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}