#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;

auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : a)
    i--;
  for (auto i : ranges::views::iota(0, n)) {
    if (a[i] < i || a[a[i]] != a[i]) {
      cout << "0\n";
      return;
    }
  }
  ll cnt = 0;
  ll ans = 1;
  vector<int> vis(n);
  for (auto i : ranges::views::iota(0, n)) {
    if (!vis[a[i]]) {
      vis[a[i]] = 1;
      cnt++;
    }
    if (a[i] == i) {
      ans = ans * cnt % MOD;
      cnt--;
    }
  }
  cout << ans << "\n";
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