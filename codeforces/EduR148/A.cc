#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  for (auto i : s) {
    cnt[i - 'a']++;
  }
  int ans = 0;
  for (auto i : cnt) {
    if (i > 1) {
      ans++;
    }
  }
  if (ans > 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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