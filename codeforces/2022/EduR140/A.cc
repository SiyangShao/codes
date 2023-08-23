#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  pair<ll, ll> x, y, z;
  cin >> x.first >> x.second >> y.first >> y.second >> z.first >> z.second;
  auto check = [&](auto a, auto b, auto c) {
    if (a.second == b.second && b.first == c.first)
      return true;
    return false;
  };
  auto a = x, b = y, c = z;
  if (check(a, b, c) || check(a, c, b) || check(b, a, c) || check(b, c, a) ||
      check(c, a, b) || check(c, b, a)) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
