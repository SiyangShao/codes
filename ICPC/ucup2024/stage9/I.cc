#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 1e6 + 7;
array<vector<int>, N> mp;
array<vector<pair<int, int>>, N> pr;
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 1; (ll)j * j <= (ll)a[i]; j++) {
      if (a[i] % j != 0)
        continue;
      int x = j, y = i / j;
      mp[x].emplace_back(i);
      if (x != y) {
        mp[y].emplace_back(i);
      }
    }
  }
  for (int i = 1; i < N; ++i) {
    if (mp[i].size() < 3)
      continue;
    for (int j = 1; j + 1 < (int)mp[i].size(); ++j) {
      int b = mp[i][j];
      int a = mp[i][j - 1];
      int c = b - a + b;
      auto it = lower_bound(mp[i].begin(), mp[i].end(), c);
      if (it == mp[i].end())
        break;
      int k = (int)(it - mp[i].begin());
      pr[i].emplace_back(j - 1, k);
    }
  }
  vector<pair<int, int>> query(q);
  vector<int> ans(q, 1), id(q);
  for (auto &[u, v] : query) {
    cin >> u >> v;
    u--, v--;
  }
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) {
    if (query[i].second != query[j].second) {
      return query[i].second < query[j].second;
    } else {
      return query[i].first < query[j].first;
    }
  });
  for (int i = 0; i < N; ++i) {
    if (pr[i].empty())
      continue;
    reverse(pr[i].begin(), pr[i].end());
  }
  for (int i = 0; i < q; i++) {
    auto [l, r] = query[id[i]];
    for (int j = N - 1; j > 1; --j) {
      if (pr[j].empty())
        continue;
      dbg(pr[j]);
      while (!pr[j].empty() && pr[j].back().second < r) {
        pr[j].pop_back();
      }
      dbg(l, r);
      dbg(j, pr[j]);
      auto it = lower_bound(pr[j].begin(), pr[j].end(),
                            pair<int, int>{l, N + 5}, greater<>());
      if (it != pr[j].end()) {
        dbg(*it);
      }
      if (it == pr[j].end() || (it->first) > r) {
        continue;
      }
      ans[id[i]] = j;
      break;
    }
  }
  for (auto i : ans) {
    cout << i << '\n';
  }
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
