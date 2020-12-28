#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  n *= 2;
  string s;
  cin >> s;
  vector<ll> change;
  change.clear();
  ll cur = 0;
  for (ll i = n - 1; i >= 0; i -= 2) {
    if (s[i] == s[i - 1]) {
      continue;
    }
    // s[i] != s[i-1]
    assert(cur == s[i] - '0' || cur == s[i - 1] - '0');
    if (cur == s[i] - '0') {
      change.emplace_back(i);
      cur ^= 1;
    } else {
      change.emplace_back(i - 1);
      cur ^= 1;
    }
  }
  if (change.size() % 2 == 1) {
    cout << "-1\n";
    return;
  }
  cout << change.size();
  if (!change.empty()) {
    reverse(change.begin(), change.end());
    for (auto &i : change) {
      cout << " " << i + 1;
    }
  }
  cout << "\n";

  for (ll i = 1; i <= n; i += 2) {
    cout << i << " ";
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