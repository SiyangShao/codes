#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  ll c;
  cin >> n >> c;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  ranges::sort(a);
  if (c >= 0) {
    for (auto i : a) {
      cout << i << ' ';
    }
    cout << "\n";
    return;
  }
  ranges::reverse(a);
  for (auto i = a.begin(); i != a.end(); ++i) {
    for (auto j = prev(a.end()); j != i; --j) {
      auto dif = -abs(*j - *(prev(j)) - c);
      if (j != prev(a.end())) {
        dif -= abs(*next(j) - *j - c);
        dif += abs(*next(j) - *(prev(j)) - c);
      }
      if (i == a.begin()) {
        dif += abs(*i - *j - c);
      } else {
        dif -= abs(*i - *(prev(i)) - c);
        dif += abs(*i - *j - c);
        dif += abs(*j - *(prev(i)) - c);
      }
      if (dif == 0) {
        for (auto k = j; k != i; --k) {
          swap(*k, *(prev(k)));
        }
        break;
      }
    }
  }
  for (auto i : a) {
    cout << i << ' ';
  }
  cout << "\n";
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