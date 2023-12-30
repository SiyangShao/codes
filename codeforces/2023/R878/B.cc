#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  auto ano = n;
  while (ano) {
    ans++;
    ano /= 2;
  }
  if (ans > k) {
    cout << (1LL << k) << "\n";
  } else {
    cout << n + 1 << "\n";
  }
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