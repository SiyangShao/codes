#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll sum = 1, num = 1;
  ll op = 0;
  for (auto i : a) {
    if (i == -1) {
      if (num <= 1) {
        if (op) {
          op--;
          sum++;
          num++;
        } else {
          cout << "-1\n";
          return;
        }
      } else
        num--;
    } else if (i == 1) {
      sum++, num++;
    } else {
      if (num > 1)
        op++, num--;
      else
        sum++, num++;
    }
  }
  ll gc = gcd(sum, num);
  sum /= gc, num /= gc;
  cout << sum << " " << num << "\n";
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