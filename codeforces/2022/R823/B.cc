#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr ld eps = 1e-8;
auto solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  ll mx_t = 0;

  for (auto &[x, t] : a) {
    cin >> x;
  }
  for (auto &[x, t] : a) {
    cin >> t;
    mx_t = max(mx_t, t);
  }
  vector<pair<ll, ll>> b(n);
  ll L = 1e9, R = 0;
  for (ll i = 0; i < n; ++i) {
    ll del_t = mx_t - a[i].second;
    b[i].first = a[i].first - del_t;
    b[i].second = a[i].first + del_t;
    L = min(L, b[i].second);
    R = max(R, b[i].first);
  }
  // for(auto &[l,r]: b){
  //   cout<<l<<" "<<r<<"\n";
  // }
  if ((L + R) % 2 == 1) {
    cout << (L + R) / 2 << ".5\n";
  } else {
    cout << (L + R) / 2 << "\n";
  }
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