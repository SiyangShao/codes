#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<ll> b(n + 1), c(n + 1);
  map<ll, vector<ll>> mpx, mpy;
  mpx[0].emplace_back(0);
  for (ll i = 1; i <= n; ++i) {
    b[i] = a[i - 1];
    c[i] = a[i - 1];
    c[i] += c[i - 1];
    b[i] ^= b[i - 1];
    if (i % 2 == 0) {
      mpx[b[i]].emplace_back(i);
    } else {
      mpy[b[i]].emplace_back(i);
    }
  }
  while (q--) {
    int L, R;
    cin >> L >> R;
    if (L == R) {
      if (a[L - 1] == 0) {
        cout << "0\n";
      } else {
        cout << "-1\n";
      }
      continue;
    } else if (L == R - 1) {
      if (a[L - 1] == 0 && a[R - 1] == 0) {
        cout << "0\n";
      } else {
        cout << "-1\n";
      }
      continue;
    }
    L--;
    if (c[R] - c[L] == 0) {
      cout << "0\n";
      continue;
    }
    if (b[R] != b[L]) {
      cout << "-1\n";
      continue;
    }
    if ((R - L) % 2 == 1) {
      cout << "1\n";
      continue;
    }

    auto &&vec = (L % 2 == 1 ? mpx[b[L]] : mpy[b[L]]);
    ll pos1 = upper_bound(vec.begin(), vec.end(), R) -
              upper_bound(vec.begin(), vec.end(), L);
    if (pos1 == 0) {
      cout << "-1\n";
    } else {
      if (a[L] == 0 || a[R - 1] == 0) {
        cout << "1\n";
      } else {
        cout << "2\n";
      }
    }
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}