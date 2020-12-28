#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll get() {
  ll y;
  cin >> y;
  return y;
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll cnt = 0;
  ranges::sort(a);
  for (auto i : a) {
    if (cnt == i) {
      cnt++;
    } else {
      break;
    }
  }
  cout << cnt << endl;
  while (true) {
    ll y = get();
    assert(y != -2);
    if (y == -1) {
      return;
    }
    cout << y << endl;
  }
}
auto main() -> int {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}