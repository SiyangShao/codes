#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  // Observation: If it is not bipartate graph, there should be **at least one
  // edge** in it has both endpoint The edge should be in a odd-circle
  vector<int> col(n, -1), fa(n), dep(n);
  fa[0] = -1, col[0] = 0;
  function<void(int)> dfs = [&](int u) {
    for (auto v : E[u]) {
      if (col[v] == -1) {
        fa[v] = u;
        dep[v] = dep[u] + 1;
        col[v] = col[u] ^ 1;
        dfs(v);
      }
    }
  };
  dfs(0);
  vector<int> f(n), f2(n);
  int badEdges = 0;
  bool bad = false;
  for (int u = 0; u < n; ++u) {
    for (auto v : E[u]) {
      if (col[u] == 0 && col[v] == 0) {
        bad = true;
      }
      if (dep[u] < dep[v] && fa[v] != u) {
        if (col[u] == col[v]) {
          badEdges++;
          f[v]++;
          f[u]--;
        } else {
          f2[v]++;
          f2[u]--;
          // f[v]--;
          // f[u]++;
        }
      }
    }
  }
  if (badEdges <= 1) {
    if (bad) {
      for (int i = 0; i < n; ++i) {
        col[i] ^= 1;
      }
    }
    cout << "YES\n";
    for (auto &i : col) {
      cout << i;
    }
    cout << "\n";
    return;
  }

  int modify = -1;
  dfs = [&](int u) {
    for (auto v : E[u]) {
      if (u == fa[v]) {
        dfs(v);
        f[u] += f[v];
        f2[u] += f2[v];
      }
    }
    if(f[u] == badEdges && f2[u] == 0){
      modify = u;
    }
  };
  dfs(0);
  for (int i = 1; i < n; ++i) {
    if (f[i] == badEdges && f2[i] == 0) {
      modify = i;
      break;
    }
  }
  if (modify == -1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  dfs = [&](int u) {
    col[u] ^= 1;
    for (auto v : E[u]) {
      if (fa[v] == u) {
        dfs(v);
      }
    }
  };
  dfs(modify);
  if (col[modify] == 0) {
    for (int i = 0; i < n; ++i) {
      col[i] ^= 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << col[i];
  }
  cout << "\n";
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