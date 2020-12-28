#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using i64 = long long;
constexpr i64 MOD = 998'244'353;
i64 pow2(auto n) {
  auto res = 0;
  while ((1LL << res) <= n)
    res++;
  return res;
}
i64 qpow(auto x, auto y) {
  auto res = 1LL;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  i64 l, r;
  cin >> l >> r;
  auto size = dbg(pow2(r / l));
  if (size == 1) {
    cout << 1 << " " << r - l + 1 << "\n";
    return;
  }
  i64 mx = r / qpow(2, size - 1);
  dbg(mx);
  i64 ans = mx - l + 1;
  i64 ano_mx = r / (qpow(2, size - 2) * 3);
  if (ano_mx >= l) {
    ans = ans + (ano_mx - l + 1) * (size - 1) % MOD;
    ans %= MOD;
  }

  cout << size << " " << ans << "\n";
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