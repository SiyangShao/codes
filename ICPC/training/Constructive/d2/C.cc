#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll one = 0;
  for (auto &i : s) {
    one += i - '0';
  }
  if (one % 2 == 1) {
    cout << "-1\n";
    return;
  }
  vector<ll> change_pos;
  for (ll i = 0; i < n * 2; i += 2) {
    if (s[i] == s[i + 1])
      continue;
    if (change_pos.empty()) {
      if (s[i] == '1') {
        change_pos.emplace_back(i);
      } else {
        change_pos.emplace_back(i + 1);
      }
    } else {
      ll id = change_pos.back();
      if (s[id] == s[i]) {
        change_pos.emplace_back(i + 1);
      } else {
        change_pos.emplace_back(i);
      }
    }
  }
  cout << change_pos.size() << " ";
  for (auto &i : change_pos) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  for (ll i = 0; i < n; ++i) {
    cout << i * 2 + 1 << " ";
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