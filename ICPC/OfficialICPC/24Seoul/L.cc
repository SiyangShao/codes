#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
tuple<bool, pll, pll> getLR(pll x, pll y) {
  ll dif1 = abs(x.first - y.first);
  ll dif2 = abs(x.second - y.second);
  auto d = gcd(dif1, dif2);
  if (d <= 1) {
    return {false, pll{}, pll{}};
  }
  auto stpx = (x.first - y.first) / d, stpy = (x.second - y.second) / d;
  pll a, b;
  a.first = x.first - stpx;
  b.first = y.first + stpx;
  a.second = x.second - stpy;
  b.second = y.second + stpy;
  return {true, a, b};
}
auto cal(pll x, pll y, pll z) {
  return abs(x.first * (y.second - z.second) + y.first * (z.second - x.second) +
             z.first * (x.second - y.second));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  pair<ll, ll> A, B, C;
  cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;
  vector<pll> lx, ly, lz;
  {
    auto [flg, a, b] = getLR(A, B);
    if (!flg) {
      cout << "-1\n";
      return 0;
    }
    lx.emplace_back(a), lx.emplace_back(b);
  }
  {
    auto [flg, a, b] = getLR(A, C);
    if (!flg) {
      cout << "-1\n";
      return 0;
    }
    ly.emplace_back(a), ly.emplace_back(b);
  }
  {
    auto [flg, a, b] = getLR(C, B);
    if (!flg) {
      cout << "-1\n";
      return 0;
    }
    lz.emplace_back(a), lz.emplace_back(b);
  }
  ll mx = 0, mi = LLONG_MAX;
  for (auto i : lx) {
    for (auto j : ly) {
      for (auto k : lz) {
        mx = max(mx, cal(i, j, k));
        mi = min(mi, cal(i, j, k));
      }
    }
  }
  cout << mx << " " << mi << "\n";
}
