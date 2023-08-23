#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> topoSort(vector<vector<int>> &E, int n) {
  queue<int> Q;
  vector<int> in(n, 0);
  for (int i = 0; i < n; ++i) {
    for (auto v : E[i]) {
      in[v]++;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0) {
      Q.emplace(i);
    }
  }
  vector<int> vec;
  while (!Q.empty()) {
    auto u = Q.front();
    vec.emplace_back(u);
    Q.pop();
    for (auto v : E[u]) {
      in[v]--;
      if (in[v] == 0) {
        Q.emplace(v);
      }
    }
  }
  return vec;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  vector<vector<int>> G(n), revG(n);
  vector<int> in(n), id(n);
  iota(id.begin(), id.end(), 0);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    in[v]++;
  }
  sort(id.begin(), id.end(), [&](int x, int y) { return in[x] < in[y]; });
  vector<int> dfn(n, -1), in_st(n, 0);
  int t = 0;
  bool flag = false;
  function<void(int)> dfs = [&](int u) {
    dfn[u] = t++;
    in_st[u] = 1;
    for (auto v : E[u]) {
      if (dfn[v] == -1) {
        G[u].emplace_back(v);
        dfs(v);
      } else {
        if (in_st[v] && dfn[v] < dfn[u]) {
          flag = true;
          // 返祖边
          revG[u].emplace_back(v);
        } else {
          G[u].emplace_back(v);
        }
      }
    }
    in_st[u] = 0;
  };
  for (auto i : id) {
    if (dfn[i] == -1)
      dfs(i);
  }
  auto vec = topoSort(G, n);
  auto vvec = topoSort(revG, n);
  if (flag) {
    cout << "2\n";
  } else {
    cout << "1\n";
  }
  for (auto i : vec) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  if (!flag)
    return;
  for (auto i : vvec) {
    cout << i + 1 << " ";
  }
  cout << "\n";
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
