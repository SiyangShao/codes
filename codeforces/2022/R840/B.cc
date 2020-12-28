#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> a(n);
  for (auto &[l, r] : a) {
    cin >> r;
  }
  for (auto &[l, r] : a) {
    cin >> l;
  }
  sort(a.begin(), a.end());
  ll cnt = 0;
  bool flag = false;
  for (auto &[l, r] : a) {
    r -= cnt;
    if (r > 0 && flag) {
      k -= l;
      flag = false;
    }
    while (k > 0 && r > 0) {
      cnt += k;
      r -= k;
      if (r > 0)
        k -= l;
      else
        flag = true;
    }
    if (r <= 0)
      continue;
    assert(k <= 0 && r > 0);
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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