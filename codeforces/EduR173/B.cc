#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, d;
  cin >> n >> d;
  cout << "1";
  // check 3:
  if (d % 3 == 0 || n >= 3) {
    cout << " 3";
  }
  // check 5:
  if (d == 5) {
    cout << " 5";
  }
  // check 7:
  if (d == 7 || n >= 3) {
    cout << " 7";
  }
  // check 9:
  if (d == 9 || n >= 6 || ((d == 3 || d == 6) && n >= 3)) {
    cout << " 9";
  }
  cout << "\n";
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
