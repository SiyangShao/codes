#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
  vector<int> fa;
  DSU(int n) : fa(n) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u]) {
      fa[u] = find(fa[u]);
    }
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    fa[u] = v;
  }
};
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> b(n);
  for (auto &i : b) {
    cin >> i;
  }
  // vector<vector<int>> E(n);
  vector<int> nxt(n);
  vector<int> vis(n, 0), in(n, 0);
  DSU dsu(n);
  for (int i = 1; i <= n; ++i) {
    // l[i] = i
    // cout << i << " " << b[i - 1] << "\n";
    // E[i - 1].emplace_back(b[i - 1] - 1);
    if (k == 1 && i != b[i - 1]) {
      cout << "No\n";
      return;
    }
    nxt[i - 1] = b[i - 1] - 1;
    dsu.merge(i - 1, b[i - 1] - 1);
    in[b[i - 1] - 1]++;
  }
  if (k == 1) {
    cout << "Yes\n";
    return;
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n; ++i) {
    E[dsu.find(i)].emplace_back(i);
  }
  function<int(int)> dfs = [&](int u) {
    int v = nxt[u];
    if (!vis[v]) {
      vis[v] = vis[u] + 1;
      return dfs(v);
    } else {
      return vis[u] - vis[v];
    }
  };
  for (int i = 0; i < n; ++i) {
    if (E[i].empty())
      continue;
    int u = -1;
    for (auto j : E[i]) {
      if (in[j] == 0) {
        u = j;
        break;
      }
    }
    // cout << u << " ";
    if (u == -1) {
      int size = (int)E[i].size();
      // cout << size << " ";
      if (size != k) {
        cout << "No\n";
        return;
      }
    } else {
      int size = dfs(u) + 1;
      // cout << size << " ";
      if (size != k) {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
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