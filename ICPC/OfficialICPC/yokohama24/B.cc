#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto check(ll x) {
  vector<ll> v;
  while (x) {
    if (x & 1)
      v.emplace_back(1);
    else
      v.emplace_back(0);
    x >>= 1;
  }
  return v;
}
auto solve() {
  ll a, b;
  cin >> a >> b;
  if (a == b) {
    cout << a << "\n";
    return;
  }
  auto va = check(a), vb = check(b);
  while (va.size() != vb.size()) {
    va.emplace_back(0);
  }
  reverse(va.begin(), va.end());
  reverse(vb.begin(), vb.end());
  ll sz = va.size();
  auto vc = vector<ll>(sz, 0);
  ll ans = 0;
  ll cnt = sz;
  for (ll i = 0; i < sz; i++) {
    if (va[i] != vb[i]) {
      assert(va[i] == 0 && vb[i] == 1);
      vc[i] = 1;
      ans = ans * 2;
      cnt = i;
      break;
    } else {
      vc[i] = va[i];
      ans = ans * 2 + va[i];
    }
  }
  ll base = 1;
  for (ll i = cnt + 1; i < sz; i++) {
    ans = ans * 2;
    base = base * 2;
  }
  if (ans >= a && ans <= b) {
    cout << ans << "\n";
    return;
  }
  ans += base;
  ll tmp = ans;
  for (ll i = cnt + 1; i < sz; i++) {
    tmp -= base;
    base /= 2;
    tmp += base;
    if (tmp >= a && tmp <= b) {
      ans = min(ans, tmp);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
