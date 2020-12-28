#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr int N = 5e5 + 6;
array<ll, N> Frac, invFrac;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
void init() {
  Frac[0] = 1;
  for (int i = 1; i < N; ++i) {
    Frac[i] = Frac[i - 1] * i % mod;
  }
  invFrac[N - 1] = qpow(Frac[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; --i) {
    invFrac[i] = invFrac[i + 1] * (i + 1) % mod;
  }
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n), w(n);
  vector<int> b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i, i--;
  for (auto &i : w)
    cin >> i;
  vector<int> vis(n), dis(n, -1);
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    if (a[u] < a[b[u]]) {
      dis[u] = 0;
      return;
    }
    if (a[u] < a[b[u]] + w[b[u]]) {
      if (!vis[b[u]])
        dfs(b[u]);
      if (dis[b[u]] != -1)
        dis[u] = dis[b[u]] + 1;
    }
  };
  for (int i = 0; i < n; ++i) {
    if (!vis[i])
      dfs(i);
  }
  dbg(dis);
  for (int i = 0; i < n; ++i) {
    if (dis[i] != -1)
      a[i] += w[i] * invFrac[dis[i] + 1] % mod;
    a[i] %= mod;
    cout << a[i] << " ";
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}