#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  ll l = 1, r = n;
  ll L = 1, R = n;
  while (r - l + 1 >= 4) {
    if (min(a[l], a[r]) != L && max(a[l], a[r]) != R) {
      cout << l << " " << r << "\n";
      return;
    }
    if (min(a[l], a[r]) == L && max(a[l], a[r]) == R) {
      l++, r--;
      L++, R--;
    } else {
      if (min(a[l], a[r]) == L) {
        if (a[l] == L) {
          l++;
        } else {
          r--;
        }
        L++;
      } else {
        if (a[l] == R) {
          l++;
        } else {
          r--;
        }
        R--;
      }
    }
  }
  cout << "-1\n";
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
