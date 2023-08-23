#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
constexpr ll inf = 1e16;
constexpr int lim = 1000;
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<int> size(n), fa(n, -1), hson(n, -1);
  function<void(int)> dfs = [&](int u) {
    size[u] = 1;
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
      fa[v] = u;
      dfs(v);
      size[u] += size[v];
      if (hson[u] == -1 || size[v] > size[hson[u]]) {
        hson[u] = v;
      }
    }
  };
  dfs(0);
  using datatype = vector<array<ll, 2>>;
  function<void(datatype &, datatype)> merge = [](datatype &x, datatype y) {
    int a = (int)x.size() - 1;
    int b = (int)y.size() - 1;
    datatype nxt(min(a + b, lim) + 1, {inf, inf});
    for (int i = 1; i <= min(a, lim); ++i) {
      for (int j = 1; j <= b; ++j) {
        nxt[i][0] = min(nxt[i][0], (x[i][0] + y[j][1]) % MOD);
        nxt[i][1] = min(nxt[i][1], (x[i][1] + y[j][0]) % MOD);
        if (i + j <= lim) {
          nxt[i + j][0] = min(nxt[i + j][0], (x[i][0] + y[j][0] + i * j) % MOD);
          nxt[i + j][1] =
              min(nxt[i + j][1], (x[i][1] + y[j][1] + 2 * i * j) % MOD);
        }
      }
    }
    x = nxt;
  };
  function<datatype(int)> dp = [&](int u) {
    datatype ans(2, {inf, inf});
    ans[1][0] = 1, ans[1][1] = 2;
    if (hson[u] != -1) {
      merge(ans, dp(hson[u]));
    }
    for (auto v : E[u]) {
      if (v == fa[u] || v == hson[u])
        continue;
      merge(ans, dp(v));
    }
    return ans;
  };
  auto ans = dp(0);
  ll res = inf;
  for (auto i : ans) {
    res = min(res, i[0]);
    res = min(res, i[1]);
  }
  cout << 1LL * n * (n + 1) - res << "\n";
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