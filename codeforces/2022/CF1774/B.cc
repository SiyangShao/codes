#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(m);
  for (auto &i : a) {
    cin >> i;
  }
  if (m < k) {
    cout << "NO\n";
    return;
  }
  ll seg = n / k + (n % k == 0 ? 0 : 1);
  bool q = n % k != 0;
  ll res = 0;
  for (auto i : a) {
    if (i > seg) {
      cout << "NO\n";
      return;
    } else if (i == seg) {
      if (q) {
        res++;
      }
    }
  }
  if (res > n % k) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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