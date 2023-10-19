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
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
bool is_sqrt(ll A) {
  ll x = (ll)sqrt(A);
  return A == x * x;
}
auto solve() {
  ll A, B;
  cin >> A >> B;
  bool flag = is_sqrt(A);
  ll mdB = B % MOD;
  vector<ll> ans;
  for (ll i = 2; i * i <= A; ++i) {
    ll cnt = 0;
    while (A % i == 0) {
      A /= i;
      cnt++;
    }
    if (cnt != 0) {
      ans.emplace_back(cnt);
    }
  }
  if (A != 1) {
    ans.emplace_back(1);
  }
  dbg(ans);
  ll num = 1;
  for (auto i : ans) {
    num = num * (i * mdB % MOD + 1) % MOD;
  }
  if (B % 2 == 0 || flag) {
    // num should be odd
    num = (num + 1) % MOD;
  }

  num = num * qpow(2, MOD - 2) % MOD;
  num = num * mdB % MOD;
  dbg(num);
  if (B % 2 == 0 || flag) {
    num = (num + MOD - mdB) % MOD;
    num = num + (B / 2) % MOD;
    num %= MOD;
  }
  cout << num << "\n";
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