#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<pair<ll, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end());
  cout << n - 1 << "\n";
  ll cur = a[0].first;
  for (int i = 1; i < n; ++i) {
    cout << a[i].second << " ";
    ll nxt = a[i].first / cur;
    if (a[i].first % cur != 0)
      nxt++;
    cout << nxt * cur - a[i].first << "\n";
    cur = max(cur, nxt * cur);
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
