#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll a, b, c, d, v, t;
  cin >> a >> b >> c >> d >> v >> t;
  ll x = lcm(a, c);
  ll res = t % x, cnt = t / x;
  vector<ll> p;
  ll ans = 0;
  for (ll i = 0; i < x; i += a) {
    if (i <= res) {
      ans += b;
    }
    ans += b * cnt;
    p.emplace_back(i);
  }
  for (ll i = 0; i < x; i += c) {
    if (i <= res) {
      ans += d;
    }
    ans += d * cnt;
    p.emplace_back(i);
  }
  p.emplace_back(x);
  ranges::sort(p);
  for (int i = 1; i < (int)p.size(); ++i) {
    if (p[i] - p[i - 1] > v) {
      ans -= cnt;
      if (p[i] <= res) {
        ans--;
      }
    }
  }
  ans--;
  cout << ans << "\n";
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