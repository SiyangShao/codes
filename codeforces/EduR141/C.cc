#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto b = a;
  sort(b.begin(), b.end());
  vector<ll> pre(n + 1, 0);
  for (ll i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + b[i - 1];
  }
  auto it = upper_bound(pre.begin(), pre.end(), m);
  assert(it != pre.begin());
  auto w = prev(it);
  ll win = w - pre.begin();
  if (win != n && win != 0 && *prev(w) + a[win] <= m) {
    win++;
  }
  cout << n - win + 1 << "\n";
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
