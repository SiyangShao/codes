#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<int>> E(n + 1), revE(n + 1);
  for (int i = 0; i < n; ++i) {
    if (i + a[i] < 0 || i + a[i] >= n) {
      E[i].emplace_back(n);
      revE[n].emplace_back(i);
    } else {
      E[i].emplace_back(i + a[i]);
      revE[i + a[i]].emplace_back(i);
    }
  }
  vector<int> vis(n), vv(n + 1), bef(n + 1);
  ll ans = 0;
  bool flag = false;
  function<void(int)> dfs = [&](int u) {
    if (u == n) {
      flag = true;
      return;
    }
    if (vis[u])
      return;
    vis[u] = 1;
    ans += (n - u) + u + 1;
    dfs(E[u][0]);
  };
  dfs(0);
  function<void(int)> dp = [&](int u) {
    assert(!vv[u]);
    vv[u] = 1;
    bef[u] = 1;
    for (auto v : revE[u]) {
      dp(v);
      bef[u] += bef[v];
    }
  };
  dp(n);
  vector<int> vvv(n);
  ll tot = 0;
  for (int i = 0; i < n; ++i) {
    if (vv[i])
      tot++;
  }
  function<void(int)> ddfs = [&](int u) {
    if (u == n || vvv[u])
      return;
    vvv[u] = 1;
    ans += (tot - bef[u]);
    ddfs(E[u][0]);
  };
  ddfs(0);
  if (flag) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (vis[i])
        cnt++;
    }
    ans += (n - cnt) * (n * 2 + 1);
  }
  cout << ans << "\n";
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