#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, q;
  cin >> n >> q;
  // assert(q == 1); // For C1, q==1
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<ll> s(n + 1), x(n + 1);
  vector<ll> v;
  for (ll i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + a[i - 1];
    x[i] = x[i - 1] ^ a[i - 1];
    if (a[i - 1] != 0) {
      v.emplace_back(i);
    }
  }
  function<ll(ll, ll)> f = [&](ll l, ll r) {
    return s[r] - s[l - 1] - (x[r] ^ x[l - 1]);
  };
  while (q--) {
    ll l, r;
    cin >> l >> r;
    if (v.empty()) {
      cout << l << " " << l << "\n";
      continue;
    }
    const ll ans = f(l, r);
    auto it1 = lower_bound(v.begin(), v.end(), l);
    if (it1 == v.end()) {
      cout << l << " " << l << "\n";
      continue;
    }
    auto it2 = upper_bound(v.begin(), v.end(), r);
    if (it1 == it2) {
      cout << l << " " << l << "\n";
      continue;
    }
    it2--;
    ll mlen = r - l + 1;
    pair<ll, ll> output = {l, r};
    l = it1 - v.begin(), r = it2 - v.begin();
    for (ll i = l; i <= min(r, l + 32); ++i) {
      for (ll j = r; j >= max(i, r - 32); --j) {
        if (f(v[i], v[j]) == ans && v[j] - v[i] + 1 < mlen) {
          mlen = v[j] - v[i] + 1;
          output = {v[i], v[j]};
        }
      }
    }
    assert(f(output.first, output.second) == f(v[l], v[r]));
    cout << output.first << " " << output.second << "\n";
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