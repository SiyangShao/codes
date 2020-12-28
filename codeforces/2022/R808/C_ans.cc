#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct dsu {
public:
  dsu() : _n(0) {}
  explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y)
      return x;
    if (-parent_or_size[x] < -parent_or_size[y])
      std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0)
      return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int> &v) { return v.empty(); }),
        result.end());
    return result;
  }

private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;
};
auto solve() {
  // since the i-th edge in the input has weight i
  // the MST in the graph is **unique**
  int n, m;
  cin >> n >> m;
  dsu DSU(n);
  vector<vector<int>> E(n), Q(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (DSU.same(u, v)) {
      Q[u].emplace_back(v);
      Q[v].emplace_back(u);
    } else {
      DSU.merge(u, v);
      E[u].emplace_back(v);
      E[v].emplace_back(u);
    }
  }
  vector<int> ans(n), nxt(n, -1), dp(n);
  function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : Q[u]) {
      if (nxt[v] != -1) { // v is under the dfs root of u
        dp[0]++;
        dp[nxt[v]]--;
      } else {
        dp[v]++;
      }
    }
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      nxt[u] = v;
      dfs(v, u);
    }
    nxt[u] = -1;
  };
  dfs(0, 0);
  function<void(int, int)> dpdfs = [&](int u, int fa) {
    if (dp[u] == m - (n - 1)) {
      ans[u] = 1;
    } else {
      ans[u] = 0;
    }
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dp[v] += dp[u];
      dpdfs(v, u);
    }
  };
  for (auto &i : ans) {
    cout << i;
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