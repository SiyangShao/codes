#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> s(n + 1), a(n + 1);
  for (ll i = n - k + 1; i <= n; ++i) {
    cin >> s[i];
  }
  if (k == 1) {
    cout << "Yes\n";
    return;
  }
  for (ll i = n - k + 2; i <= n; ++i) {
    a[i] = s[i] - s[i - 1];
    if (i != n - k + 2 && a[i] < a[i - 1]) {
      cout << "No\n";
      return;
    }
  }
  ll pos = a[n - k + 2];
  if (pos * (n - k + 1) >= s[n - k + 1]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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