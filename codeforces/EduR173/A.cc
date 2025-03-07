#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll x;
  cin >> x;
  ll num = 1;
  while (x > 3) {
    x /= 4;
    num *= 2;
  }
  cout << num << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
