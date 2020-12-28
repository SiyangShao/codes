#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
auto solve() {
  int n, tot;
  cin >> n >> tot;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  int m1, m2;
  cin >> m1;
  vector<int> a(n, 0), b(n, 0), resA(n, 0), resB(n, 0);
  for (int i = 0; i < m1; ++i) {
    int tmp;
    cin >> tmp;
    tmp--;
    a[tmp] = 1;
  }
  cin >> m2;
  for (int i = 0; i < m2; ++i) {
    int tmp;
    cin >> tmp;
    tmp--;
    b[tmp] = 1;
  }
  function<void(int, int)> init = [&](int u, int fa) {
    if (a[u])
      resA[u]++;
    if (b[u])
      resB[u]++;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      init(v, u);
      resA[u] += resA[v];
      resB[u] += resB[v];
    }
  };
  init(0, 0);

  vector<int> nxt(n, -1);
  vector<int> A(n), B(n);
  function<void(int, int, int, int)> go = [&](int u, int fa, int rt, int len) {
    if (len > tot) {
      len--;
      rt = nxt[rt];
    }
    A[rt] = 1, B[u] = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (resA[v] || resB[v]) {
        nxt[u] = v;
        go(v, u, rt, len + 1);
      }
    }
  };
  function<int(int, int)> calA = [&](int u, int fa) {
    int ans = 0;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (A[v]) {
        ans += 2 + calA(v, u);
      }
    }
    return ans;
  };
  function<int(int, int)> calB = [&](int u, int fa) {
    int ans = 0;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (B[v]) {
        ans += 2 + calB(v, u);
      }
    }
    return ans;
  };
  function<int(int, int)> dfs = [&](int u, int fa) {
    int dis = 0;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (resA[v] != 0 && resB[v] != 0) {
        // Both x and y move to v is best
        dis += 4 + dfs(v, u);
      } else if (resA[v] != 0 || resB[v] != 0) {
        // dis += 2 + nxt(v, u, tot - 1);
        nxt[u] = v;
        go(v, u, u, 1);
        dis += calA(v, u) + (A[v] ? 2 : 0);
        dis += 2 + calB(v, u);
      }
    }
    // cout << u << " " << fa << " "
    //      << "dfs"
    //      << " " << dis << "\n";
    return dis;
  };
  cout << dfs(0, 0) << "\n";
}
auto main() -> signed {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}