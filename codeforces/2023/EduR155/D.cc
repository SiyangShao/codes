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
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<ll> b(n), c(n);
  function<ll()> cal = [&]() {
    c = b;
    for (int i = 1; i < n; ++i) {
      c[i] ^= c[i - 1];
    }
    ll zero_len = 0, one_len = 0;
    ll zero = 0, one = 0;
    for (int i = 0; i < n; ++i) {
      if (c[i]) {
        one_len = (one_len + i + 1) % MOD;
        one++;
      } else {
        zero_len = (zero_len + i + 1) % MOD;
        zero++;
      }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = (ans + one_len) % MOD;
      one_len = (one_len + MOD - one) % MOD;
      zero_len = (zero_len + MOD - zero) % MOD;
      if (b[i]) {
        one--;
        swap(one, zero);
        swap(one_len, zero_len);
      } else {
        zero--;
      }
    }
    return ans;
  };
  ll ans = 0, cnt = 1;
  for (ll i = 0; i < 32; ++i) {
    for (int j = 0; j < n; ++j) {
      b[j] = (a[j] >> i) & 1;
    }
    ans = (ans + cal() * cnt % MOD) % MOD;
    cnt = cnt * 2 % MOD;
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