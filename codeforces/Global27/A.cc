#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...)                                                               \
  {}
#endif
using namespace std;
using ll = long long;
auto solve() {
  ll n, m, r, c;
  cin >> n >> m >> r >> c;
  ll res = n - r;
  ll base = res * m + res * (m - 1);
  ll cur = m - c;
  base += cur;
  cout << base << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
