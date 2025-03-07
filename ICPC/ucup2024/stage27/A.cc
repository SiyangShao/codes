#include <bits/stdc++.h>
using namespace std;
constexpr int N = 12500;
using bst = bitset<N>;
constexpr int M = 5e5 + 5e4 + 10;
vector<bst> dp;
array<int, M> lp, rp, hashp;
map<pair<int, int>, int> mp;
auto solve() {
  int n, q;
  fill(lp.begin(), lp.end(), -1);
  fill(rp.begin(), rp.end(), -1);
  fill(hashp.begin(), hashp.end(), -1);
  cin >> n >> q;
  auto dfs = [&](auto self, int x) -> pair<int, bst> {
    bst res;
    if (x < n) {
      res[x / 4] = 1;
      return {1, res};
    }
    if (hashp[x] != -1) {
      return {1, dp[hashp[x]]};
    }
    auto [l, ll] = self(self, lp[x]);
    auto [r, rr] = self(self, rp[x]);
    res = ll | rr;
    return {max(l, r) + 1, res};
  };
  for (int i = 0; i < q; i += 50) {
    for (int j = i; j < q && j < i + 50; j++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      if (x > y) {
        swap(x, y);
      }
      int query = j + n;
      if (mp.count({x, y})) {
        query = mp[{x, y}];
      }
      mp[{x, y}] = query;
      lp[j + n] = x;
      rp[j + n] = y;
      auto [stp, res] = dfs(dfs, query);
      if (stp >= 8) {
        hashp[query] = dp.size();
        dp.emplace_back(res);
      }
      cout << res.count() * 2 << '\n';
    }
    cout.flush();
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}
