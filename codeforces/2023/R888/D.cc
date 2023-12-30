#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }
  if (a[n - 1] > (ll)n * (n + 1) / 2) {
    cout << "NO\n";
    return;
  }
  vector<ll> cnt(n * 2 + 1);
  for (int i = 1; i < n; ++i) {
    if (a[i] - a[i - 1] > 2 * n) {
      cout << "NO\n";
      return;
    }
    cnt[a[i] - a[i - 1]]++;
  }
  if (a[n - 1] < (ll)n * (n + 1) / 2) {
    for (int i = 1; i <= 2 * n; ++i) {
      if (cnt[i] > (i <= n)) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    return;
  }
  ll x = find(cnt.begin() + 1, cnt.end(), 0) - cnt.begin();
  ll y = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    if (cnt[i] > (i <= n)) {
      y = i;
      break;
    }
  }
  if (y <= x) {
    cout << "NO\n";
    return;
  }
  cnt[y]--, cnt[x]++, cnt[y - x]++;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] != 1) {
      cout << "NO\n";
      return;
    }
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