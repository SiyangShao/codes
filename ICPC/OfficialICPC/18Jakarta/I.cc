#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto YES() { cout << "TRUTH\n"; }
auto NO() { cout << "LIE\n"; }
auto solve() {
  ll n;
  cin >> n;
  vector<string> mp(n);
  for (auto &i : mp) {
    cin >> i;
  }
  reverse(mp.begin(), mp.end());
  bool flag = true;
  for (auto &i : mp) {
    if (i[0] == 'T') {
      continue;
    } else {
      flag = !flag;
    }
  }
  if (flag) {
    YES();
  } else {
    NO();
  }
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