#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> mp(10, 0);
  function<bool()> check = [&]() {
    int num = 0;
    for (auto &i : mp) {
      if (i > 0)
        num++;
    }
    for (auto &i : mp) {
      if (i > num)
        return false;
    }
    return true;
  };
  ll ans = 0;
  for (int len = 1; len <= min(n, 100); ++len) {
    // init
    for (int i = 0; i < 10; ++i) {
      mp[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
      mp[s[i] - '0']++;
    }
    if (check())
      ans++;
    for (int i = len; i < n; ++i) {
      mp[s[i - len] - '0']--;
      mp[s[i] - '0']++;
      if (check())
        ans++;
    }
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