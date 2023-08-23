#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll N = 1e7 + 7;
bitset<N> vis;
vector<ll> prime;
void init() {
  for (ll i = 2; i < N; ++i) {
    if (!vis[i]) {
      prime.emplace_back(i);
    }
    for (auto j : prime) {
      if (j * i >= N)
        break;
      vis[j * i] = true;
      if (i % j == 0) {
        break;
      }
    }
  }
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> mp;
  for (auto &i : a) {
    cin >> i;
    for (ll j = 2; j * j <= i; ++j) {
      while (i % j == 0) {
        mp[j]++;
        i /= j;
      }
    }
    if (i != 1) {
      mp[i]++;
    }
  }

  ll sum = 0;
  ll single = 0;
  for (auto [_, cnt] : mp) {
    sum += cnt / 2;
    single += cnt & 1;
  }
  sum += single / 3;
  cout << sum << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  cin >> _;
  while (_--) {
    solve();
  }
}