#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
constexpr int N = 1e5;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  bitset<N> base, cur;
  vector<pair<ll, ll>> t(n);
  vector<ll> all_t;
  for (auto &[l, r] : t) {
    cin >> l >> r;
    l *= 2;
    r = r * 2 + 1;
    all_t.emplace_back(l);
    all_t.emplace_back(r);
  }
  int k;
  cin >> k;
  vector<ll> h(k);
  for (auto &i : h) {
    cin >> i;
    i *= 2;
    all_t.emplace_back(i);
  }
  sort(all_t.begin(), all_t.end());
  all_t.erase(unique(all_t.begin(), all_t.end()), all_t.end());
  auto id = [&](ll x) {
    return lower_bound(all_t.begin(), all_t.end(), x) - all_t.begin();
  };
  int m = (int)all_t.size();
  vector<vector<int>> in(m), out(m);
  vector<int> take(m, 0);
  for (int i = 0; i < n; ++i) {
    in[id(t[i].first)].emplace_back(i);
    out[id(t[i].second)].emplace_back(i);
  }
  for (auto i : h) {
    take[id(i)]++;
  }
  for (int x = 0; x < m; ++x) {
    for (auto i : in[x]) {
      cur[i] = true;
    }
    if (take[x]) {
      base = base | cur;
    }
    for (auto i : out[x]) {
      cur[i] = false;
    }
  }
  cout << base.count() << "\n";
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