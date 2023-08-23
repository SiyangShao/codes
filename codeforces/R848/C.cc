#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  string a, b;
  cin >> a >> b;
  vector<int> same(n);
  vector<int> mp(26, 0);
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i])
      same[i] = 1;
    mp[a[i] - 'a'] = 1;
  }
  int kind = accumulate(mp.begin(), mp.end(), 0);
  vector<int> can(26);
  ll ans = 0;
  for (unsigned int i = 0; i < (1 << kind); ++i) {
    int num = popcount(i);
    if (num > k) {
      continue;
    }
    int cur = 0;
    for (int j = 0; j < 26; ++j) {
      if (mp[j] && ((i >> cur) & 1)) {
        can[j] = 1;
      } else {
        can[j] = 0;
      }
      if (mp[j])
        cur++;
    }
    ll len = 0, cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (can[a[j] - 'a'] || same[j]) {
        len++;
        cnt += len;
      } else {
        len = 0;
      }
    }
    ans = max(ans, cnt);
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