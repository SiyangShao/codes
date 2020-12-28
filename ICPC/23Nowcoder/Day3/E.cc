#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto seed = static_cast<unsigned>(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());
std::mt19937 rnd(seed);
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  vector<int> in(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u == v)
      continue;
    E[u].emplace_back(v);
  }
  bool flag = false;
  for (int _ = 0; _ < 100; ++_) {

    vector<int> dfn(n, -1), in_st(n, 0), lev(n, 0);
    int t = 0;
    function<void(int)> dfs = [&](int u) {
      dfn[u] = t++;
      in_st[u] = 1;
      shuffle(E[u].begin(), E[u].end(), rnd);
      for (auto v : E[u]) {
        if (dfn[v] == -1) { // 没访问
          lev[v] = lev[u] + 1;
          dfs(v);
        } else {
          if (in_st[v] && dfn[v] < dfn[u]) {
            continue;
          } else {
            if (lev[v] != lev[u] + 1) {
              flag = true;
            } else {
              in[v]++;
            }
          }
        }
      }
      in_st[u] = 0;
    };
    dfs(0);
  }
  if (flag) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
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
