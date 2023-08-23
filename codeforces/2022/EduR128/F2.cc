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
  vector<int> dep(n, -1), col(n, -1);
  vector<int> odd(n, 0), even(n, 0);
  int odd_edge = 0;
  function<void()> rebuild = [&]() {
    bool rev = false;
    for (int i = 0; i < n; ++i) {
      if (rev)
        break;
      for (auto v : E[i]) {
        if (col[v] == col[i] && col[i] == 0) {
          rev = true;
          break;
        }
      }
    }
    if (rev) {
      for (auto &i : col) {
        i ^= 1;
      }
    }
  };
  col[0] = dep[0] = 0;
  function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (col[v] == -1) {
        dep[v] = dep[u] + 1;
        col[v] = col[u] ^ 1;
        dfs(v, u);
      }
      if (dep[v] < dep[u] && v != fa) {
        if (col[v] == col[u]) {
          odd[u]++;
          odd[v]--;
          odd_edge++;
        } else {
          even[u]++;
          even[v]--;
        }
      }
    }
  };
  dep[0] = 0;
  dfs(0, 0);
  if (odd_edge <= 1) {
    cout << "YES\n";
    rebuild();
    for (int i = 0; i < n; ++i) {
      cout << col[i];
    }
    cout << "\n";
    return;
  }
  // delete tree edge, which should be in all odd edge
  int del = -1;
  // for(int i = 0 ; i < n; ++i){
  //   cout<<odd[i]<<" ";
  // }
  // cout<<"\n";
  function<void(int)> dp = [&](int u) {
    // cout<<u<<" "<<odd[u]<<"\n";
    // cout<<u<<" "<<add_odd<<"\n";
    for (auto v : E[u]) {
      if (dep[v] == dep[u] + 1) {
        dp(v);
        odd[u] += odd[v];
        even[u] += even[v];
      }
    }
    if (odd[u] == odd_edge && even[u] == 0) {
      del = u;
    }
  };
  dp(0);
  // cout<<del<<" "<<odd_edge<<" ";
  if (del == -1 || del == 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  function<void(int)> color = [&](int u) {
    col[u] ^= 1;
    for (auto v : E[u]) {
      if (dep[v] == dep[u] + 1) {
        color(v);
      }
    }
  };
  color(del);
  if (col[del] == 0) {
    for (auto &i : col) {
      i ^= 1;
    }
  }
  for (auto &i : col) {
    cout << i;
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