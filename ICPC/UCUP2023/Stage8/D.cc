#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<tuple<ll, ll, int>> node(n);
  for (auto &[x, y, a] : node) {
    cin >> x >> y >> a;
  }
  function<bool(ll, ll)> check = [&](ll x0, ll y0) {
    set<pair<ll, ll>> st;
    for (auto [x, y, a] : node) {
      assert(x > x0 && y > y0);
      ll dx = x - x0, dy = y - y0;
      ll t = gcd(dx, dy);
      dx /= t, dy /= t;
      if (st.contains({dx, dy}))
        return false;
      st.emplace(dx, dy);
    }
    return true;
  };
  ll x0, y0;
  random_device rd;
  mt19937_64 gen(rd());
  uniform_int_distribution<> dis(-1e6, -1e5);
  // while (true) {
  //   x0 = dis(gen);
  //   y0 = dis(gen);
  //   if (check(x0, y0))
  //     break;
  // }
  x0 = -717067, y0 = -192065;
  dbg(x0, y0);
  int line_num = 0;
  for (auto &[x, y, a] : node) {
    x -= x0;
    y -= y0;
    line_num = max(line_num, a);
  }
  sort(node.begin(), node.end(), [&](auto p, auto q) {
    auto [x, y, a] = p;
    auto t = gcd(x, y);
    x /= t, y /= t;
    auto [i, j, b] = q;
    auto k = gcd(i, j);
    i /= k, j /= k;
    // y / x > j / i
    return y * i > x * j;
  });
  dbg(node);
  vector<tuple<ll, ll, int>> new_node;
  new_node.emplace_back(node[0]);
  for (int i = 1; i < n; ++i) {
    auto [x0, y0, a] = node[i - 1];
    auto [x1, y1, b] = node[i];
    new_node.emplace_back(x0 + x1, y0 + y1, 0);
    new_node.emplace_back(node[i]);
  }
  swap(new_node, node);
  vector<vector<pair<ll, ll>>> line(line_num, vector<pair<ll, ll>>());
  for (int i = 0; i < line_num; ++i) {
    line[i].emplace_back(0, 1e7 + i);
  }
  for (auto [x, y, a] : node) {
    auto t = gcd(x, y);
    auto dx = x / t, dy = y / t;
    for (int i = 0; i < a; ++i) {
      line[i].emplace_back(x, y);
    }
    for (int i = a; i < line_num; ++i) {
      x += dx;
      y += dy;
      line[i].emplace_back(x, y);
    }
  }
  cout << line_num << "\n";
  for (auto &j : line) {
    cout << j.size();
    for (auto [x, y] : j) {
      cout << " " << x + x0 << " " << y + y0;
    }
    cout << "\n";
  }
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