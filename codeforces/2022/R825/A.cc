#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  ll A = 0, B = 0;
  for (auto &i : a) {
    cin >> i;
    A += i;
  }
  for (auto &i : b) {
    cin >> i;
    B += i;
  }
  if (a == b) {
    cout << "0\n";
    return;
  }
  if (A == B) {
    cout << "1\n";
    return;
  }
  ll i = 0, dif = abs(A - B);
  ll op = 0;
  for (i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      if (a[i] == 1) {
        a[i] = 0;
        A--;
      } else {
        a[i] = 1;
        A++;
      }
      op++;
      if (A == B) {
        break;
      }
    }
  }
  bool flag = false;
  for (; i < n; ++i) {
    if (a[i] != b[i]) {
      flag = true;
      break;
    }
  }
  if (flag) {
    cout << dif + 1 << "\n";
  } else {
    cout << min(dif + 1, op) << "\n";
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