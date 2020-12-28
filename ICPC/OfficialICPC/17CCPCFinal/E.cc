#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    ans += a;
    ans += a / 10;
    if (a % 10 != 0)
      ans++;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  for (int i = 1; i <= _; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}