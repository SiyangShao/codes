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
struct node {
  ll x, y;
  node(ll x1 = 0, ll y1 = 0) : x(x1), y(y1){};
  ll operator()(const ll t) { return (x * t + y) % MOD; }
  node operator+(const node &tmp) {
    return node{(x + tmp.x) % MOD, (y + tmp.y) % MOD};
  }
};
map<ll, node> mp;
ll qpow(ll x, ll y) {
  y %= MOD - 1;
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
ll norm(ll x) { return (x % MOD + MOD) % MOD; }
node cal(ll n) {
  if (n == 1) {
    return {1, 0};
  }
  if (mp.contains(n))
    return mp[n];
  ll mid = n >> 1;
  auto l = cal(n - mid);
  auto r = cal(mid);
  ll x = norm(l.x * 2 % MOD + r.x * 2 % MOD +
              norm(norm(qpow(2, n - mid) - 1) * norm(qpow(2, mid) - 1)));
  ll y = norm(l.y + r.y + r.x);
  return mp[n] = {x, y};
}
auto solve() {
  ll n;
  cin >> n;
  cout << cal(n)(1) << "\n";
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