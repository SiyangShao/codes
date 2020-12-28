#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define double ld
using C = complex<double>;
void solve() {
  ll n, k;
  cin >> n >> k;
  const double TPI = 3.141592653528979323846 * 2;
  vector<ll> f(n);
  for (auto &e : f)
    cin >> e;
  vector<C> cst(n), scale(n);

  for (ll t = 0; t < n; ++t) {
    for (ll s = 0; s < n; ++s) {
      C curr = std::polar((double)f[s], -(double)t * s * TPI / n);
      if (s != k)
        cst[t] += curr;
      else
        scale[t] = std::polar(ld(1.0), -(double)t * s * TPI / n);
    }
  }

  auto findRange = [](C a, C b, double B)
      -> pair<ll, ll> { // integer range of x st. |a x + b| with in [-B, B]
    std::swap(a, b);
    double _A = (b * std::conj(b)).real();
    double _B = (C(2, 0) * a * std::conj(b)).real();
    double _C = (a * std::conj(a) - B * B).real();
    double delta = _B * _B - 4 * _A * _C;
    if (delta < 0) {
      return {1, 0};
    }
    double L = (-_B - sqrt(delta)) / (2 * _A);
    double R = (-_B + sqrt(delta)) / (2 * _A);
    if (L > R) {
      swap(L, R);
    }
    return {ceil(L), floor(R)};
  };

  double lo = 0, hi = 1e7;
  double ans = hi;
  for (int T = 1; T <= 70; ++T) {
    double mi = (lo + hi) / 2;
    //        if (mi < 2) {
    //            std::cout << "haha" << std::endl;
    //        }
    ll L = -1e18, R = 1e18;
    for (ll t = 0; t < n; ++t) {
      auto [u, v] = findRange(scale[t], cst[t], mi);
      L = max(L, u), R = min(R, v);
      if (L > R)
        break;
    }
    if (L <= R) {
      hi = mi;
      ans = min(ans, mi);
    } else {
      lo = mi;
    }
  }
  cout << fixed << setprecision(12) << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int _ = 1;
  // cin >> _;
  while (_--)
    solve();
}
