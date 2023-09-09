#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll inf = 1e16;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, t;
  cin >> n >> t;
  pair<int, int> x, y;
  cin >> x.first >> x.second >> y.first >> y.second;
  vector<pair<int, int>> node(n);
  for (auto &[u, v] : node) {
    cin >> u >> v;
  }
  double base = sqrt((x.first - y.first) * (x.first - y.first) +
                     (x.second - y.second) * (x.second - y.second));
  ll int_base = static_cast<long long>(std::ceil(base));
  // one node
  ll d_one = inf;
  ll mid_d1 = -1;
  for (int i = 0; i < n; ++i) {
    auto [u, v] = node[i];
    ll dis = min(abs(x.first - u), abs(x.second - v)) + t +
             min(abs(y.first - u), abs(y.second - v));
    if (d_one > dis) {
      d_one = dis;
      mid_d1 = i;
    }
  }
  // two node
  ll dx = inf, dy = inf;
  ll nodex = -1, nodey = -1;
  for (int i = 0; i < n; ++i) {
    auto [u, v] = node[i];
    ll d1 = min(abs(x.first - u), abs(x.second - v));
    if (dx > d1) {
      dx = d1;
      nodex = i;
    }
    ll d2 = min(abs(y.first - u), abs(y.second - v));
    if (dy > d2) {
      dy = d2;
      nodey = i;
    }
  }
  ll min_dis = min(int_base, d_one);
  min_dis = min(min_dis, dx + dy + t * 2);
  if (min_dis == int_base) {
    cout << fixed << setprecision(8) << base << "\n";
    cout << "1\n";
    cout << "0 ";
    cout << y.first << " " << y.second << "\n";
  } else if (min_dis == d_one) {
    cout << d_one << "\n";
    cout << "3\n";
    auto [u, v] = node[mid_d1];
    if (abs(x.first - u) < abs(x.second - v)) {
      cout << "0 " << u << " " << x.second << "\n";
    } else {
      cout << "0 " << x.first << " " << v << "\n";
    }

    if (abs(y.first - u) < abs(y.second - v)) {
      cout << mid_d1 + 1 << " " << u << " " << y.second << "\n";
    } else {
      cout << mid_d1 + 1 << " " << y.first << " " << v << "\n";
    }
    cout << "0 " << y.first << " " << y.second << "\n";
  } else {
    cout << dx + dy + t * 2 << "\n";
    cout << "4\n";
    {
      auto [u, v] = node[nodex];
      if (abs(x.first - u) < abs(x.second - v)) {
        cout << "0 " << u << " " << x.second << "\n";
      } else {
        cout << "0 " << x.first << " " << v << "\n";
      }
    }
    {
      auto [u1, v1] = node[nodex];
      auto [u2, v2] = node[nodey];
      cout << nodex + 1 << " " << u1 << " " << v2 << "\n";
    }
    {
      auto [u, v] = node[nodey];
      if (abs(y.first - u) < abs(y.second - v)) {
        cout << nodey + 1 << " " << u << " " << y.second << "\n";
      } else {
        cout << nodey + 1 << " " << y.first << " " << v << "\n";
      }
      cout << "0 " << y.first << " " << y.second << "\n";
    }
  }
}