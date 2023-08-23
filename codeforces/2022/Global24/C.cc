#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> mp;
  for (auto &i : a) {
    cin >> i;
    mp[i]++;
  }
  sort(a.begin(), a.end());
  if (a[0] == a[n - 1]) {
    cout << n / 2 << "\n";
    return;
  }
  ll ans = 0;
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    ans++;
    mp[a[i]]--, mp[a[j]]--;
    if (a[i] == a[j]) {
      ans--;
      break;
    }
    ll res = j - i - 1;
    ans += res;
  }
  cout << ans << "\n";
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