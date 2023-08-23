#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<ll, ll>> x, y;
  for (int i = 0; i < n; ++i) {
    ll u, v;
    cin >> u >> v;
    if (u < v) {
      x.emplace_back(u, v);
    } else {
      y.emplace_back(u, v);
    }
  }
  sort(x.begin(), x.end(), [&](auto a, auto b) {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first < b.first;
  });
  sort(y.begin(), y.end(), [&](auto a, auto b) {
    if (a.second == b.second)
      return a.first < b.first;
    return a.second > b.second;
  });
  ll sum = 0, ans = 0;
  for (auto [u, v] : x) {
    sum -= u;
    if (sum < 0) {
      ans -= sum;
      sum = 0;
    }
    sum += v;
  }
  for (auto [u, v] : y) {
    sum -= u;
    if (sum < 0) {
      ans -= sum;
      sum = 0;
    }
    sum += v;
  }
  cout << ans << "\n";
}