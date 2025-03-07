#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll x;
  cin >> x;
  if (x % 33 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
