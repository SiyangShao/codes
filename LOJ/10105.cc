#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int op;
  cin >> op;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  vector<int> in(n), out(n);
  vector<int> cur(n);
  vector<pair<int, int>> edg(m);
  vector<int> vis(m);
  int _id = 1;
  for (auto &[u, v] : edg) {
    cin >> u >> v;
    u--, v--;
    in[v]++, out[u]++;
    E[u].emplace_back(_id);
    if (op == 1)
      E[v].emplace_back(-_id);
    _id++;
  }
  if (op == 1) {
    for (int i = 0; i < n; ++i) {
      if ((in[i] + out[i]) % 2 == 1) {
        cout << "NO\n";
        return 0;
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      if (in[i] != out[i]) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  vector<int> ans;
  function<void(int)> dfs = [&](int x) {
    while (cur[x] < (int)E[x].size()) {
      auto id = E[x][cur[x]];
      cur[x]++;
      if (vis[abs(id) - 1]) {
        continue;
      }
      vis[abs(id) - 1] = true;
      auto [u, v] = edg[abs(id) - 1];
      int y = u ^ v ^ x;
      dfs(y);
      ans.emplace_back(id);
    }
  };
  for (int i = 0; i < n; ++i) {
    if (cur[i] == 0 && in[i] + out[i] != 0) {
      // if not loop, should start from odd point or the only out > int point
      // start dfs and modify the no condition
      dfs(i);
      break;
    }
  }
  if ((int)ans.size() != m) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (auto i = ans.rbegin(); i < ans.rend(); ++i) {
    cout << *i << " ";
  }
}