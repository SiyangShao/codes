#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  function<bool(ll, ll)> check = [&](ll x, ll id) {
    if (a[id] >= x)
      return true;
    auto dif = x - a[id];
    for (int i = 1; i + id < n; ++i) {
      if (a[i + id] >= x - i)
        return dif <= k;
      dif += x - i - a[i + id];
    }
    return false;
  };
  function<bool(ll)> cal = [&](ll x) {
    for (int i = 0; i < n; ++i) {
      if (check(x, i))
        return true;
    }
    return false;
  };
  ll l = 0, r = 1e9, ans = 0;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (cal(mid)) {
      ans = max(ans, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
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