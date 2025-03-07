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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int must = n / 2;
  vector<int> vis(n, 0);
  for (int i = n - 1; i >= 0; --i) {
    must = min(must, (i + 1) / 2);
    if (s[i] == '1' && must) {
      vis[i] = 1;
      must--;
    }
  }
  ll ans = 0;
  dbg(vis);
  for (ll i = 0; i < n; ++i) {
    if (!vis[i])
      ans += i + 1;
  }
  cout << ans << endl;
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
