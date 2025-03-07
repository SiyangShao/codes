#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll l, r, k;
  cin >> l >> r >> k;
  ll mx = r / k;
  cout << max(mx - l + 1, 0LL) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
