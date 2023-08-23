#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<ll, ll> mp;
  for (auto &i : s) {
    mp[i - 'a']++;
  }
  for (ll i = 0; i < k; ++i) {
    bool flag = false;
    for (ll j = 0; j < min(n / k, 26LL); ++j) {
      if (mp[j] != 0) {
        mp[j]--;
      } else {
        flag = true;
        cout << char(j + 'a');
        break;
      }
    }
    if (!flag) {
      cout << char(min(n / k, 26LL) + 'a');
    }
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