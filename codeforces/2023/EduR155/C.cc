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
  string s;
  cin >> s;
  int n = static_cast<int>(s.length());
  int len = n;
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    int j = i + 1;
    while (j < n and s[i] == s[j]) {
      j++;
    }
    ans = ans * (j - i) % MOD;
    len--;
    i = j - 1;
  }
  for (int i = 1; i <= len; ++i) {
    ans = ans * i % MOD;
  }
  cout << len << " " << ans << "\n";
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