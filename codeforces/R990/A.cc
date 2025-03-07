#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  ll ans = 0;
  ll seMax = -1e8;
  for (int i = 0; i < n; i++) {
    ans += max(a[i], b[i]);
    seMax = max(seMax, min(a[i], b[i]));
  }
  ans += seMax;
  cout << ans << "\n";
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
