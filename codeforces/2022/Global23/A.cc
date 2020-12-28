#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  if (*max_element(a.begin(), a.end()) == 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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