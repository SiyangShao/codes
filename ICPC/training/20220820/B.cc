#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, s;
  cin >> n >> s;
  vector<ll> a(n);
  map<ll, ll> mp;
  for (auto &i : a) {
    cin >> i;
    mp[i]++;
    if (i + i == s && mp[i] > 2) {
      cout << "no\n";
      return;
    }
  }
  cout << "yes\n";
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