#include <bits/stdc++.h>
using namespace std;
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
  int n, m;
  cin >> n >> m;
  dsu DSU(n);
  vector<vector<int>> E(n + m);
  vector<int> id(n + m, -1);
  int new_node_id = n;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (DSU.same(u, v)) {
      id[new_node_id] = v;
      v = new_node_id;
      new_node_id++;
    } else {
      DSU.merge(u, v);
    }
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  for (int i = 0; i < n; ++i) {
    id[i] = i;
  }
  vector<int> vis(new_node_id, 0), use(new_node_id, 0);
  vector<tuple<int, int, int>> ans;
  function<void(int, int)> dfs = [&](int u, int fa) {
    vis[u] = 1;
    vector<int> cur = {};
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      if (use[v] == 0) {
        cur.emplace_back(v);
      }
    }
    if (cur.empty()) {
      return;
    }
    if (cur.size() % 2 == 0) {
      // u-fa edge didn't use
      // all u's son has been used
      for (int i = 0; i < cur.size(); i += 2) {
        ans.emplace_back(cur[i], u, cur[i + 1]);
      }
    } else {
      // u-fa edge used
      use[u] = 1;
      if (u != fa) {
        // u is not root
        ans.emplace_back(cur[0], u, fa);
      }
      for (int i = 1; i < cur.size(); i += 2) {
        ans.emplace_back(cur[i], u, cur[i + 1]);
      }
    }
  };
  for (int i = 0; i < new_node_id; ++i) {
    if (!vis[i]) {
      dfs(i, i);
    }
  }
  cout << ans.size() << "\n";
  for (auto &[x, y, z] : ans) {
    cout << id[x] + 1 << " " << id[y] + 1 << " " << id[z] + 1 << "\n";
  }
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