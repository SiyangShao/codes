#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  int flg = 0;
  for (auto &i : a) {
    cin >> i;
    if (i >= 0) {
      i = -i - 1;
    }
    if (i < 0) {
      flg++;
    }
  }
  if (flg % 2 == 0) {
    for (auto &i : a) {
      cout << i << " ";
    }
    return;
  }
  assert(*max_element(a.begin(), a.end()) < 0);
  ll mx = 0, pos = -1;
  for (ll i = 0; i < n; ++i) {
    if (a[i] < mx) {
      mx = a[i];
      pos = i;
    }
  }
  a[pos] = -a[pos] - 1;
  for (auto &i : a) {
    cout << i << " ";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}