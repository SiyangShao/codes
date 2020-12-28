#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5 + 5;
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
  vector<int> hson(n, -1), size(n, 1);
  function<void(int, int)> init = [&](int u, int fa) {
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      init(v, u);
      size[u] += size[v];
      if (hson[u] == -1 || size[v] > size[hson[u]]) {
        hson[u] = v;
      }
    }
  };
  init(0, 0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}