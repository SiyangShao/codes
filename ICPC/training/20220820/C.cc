#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto cal(ll &x, ll &y) {
  if (x >= y) {
    ll tmp = x / y;
    x %= y;
    swap(x, y);
    return tmp;
  } else {
    swap(x, y);
    return 0LL;
  }
}
auto solve() {
  ll x, y;
  cin >> x >> y;
  vector<ll> ans;
  while (x != 0 && y != 0) {
    ll cnt = cal(x, y);
    ans.emplace_back(cnt);
  }
  assert(ans.size() <= 100);
  cout << ans.size() - 1;
  for (auto i : ans) {
    cout << " " << i;
  }
  cout << "\n";
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