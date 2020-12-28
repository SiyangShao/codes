#include <bits/stdc++.h>
#include <functional>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }
  sort(a.begin(), a.end(), greater<>());
  if (a[0] * 2 > sum) {
    cout << "T\n";
    return;
  } else if (sum % 2 == 0) {
    cout << "HL\n";
    return;
  } else {
    for (ll i = 0; i < n; ++i) {
      ll mx = 0;
      for (ll j = 0; j < n; ++j) {
        if (j == i)
          continue;
        mx = max(mx, a[j]);
      }
      if (mx * 2 <= sum - 1) {
        cout << "T\n";
        return;
      }
    }
    cout << "HL\n";
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