#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v, i - 1), E[v].emplace_back(u, i - 1);
  }
  vector<int> leaf;
  for (int i = 0; i < n; ++i) {
    if ((int)E[i].size() == n - 1) {
      cout << "-1\n";
      return 0;
    }
    if ((int)E[i].size() == 1) {
      leaf.emplace_back(i);
    }
  }
  assert((int)leaf.size() >= 2);
  int rt = leaf[0];
  int center = E[rt][0].first, faid = E[rt][0].second;
  int cnt = 0;
  for (auto [v, id] : E[center]) {
    if (id < faid) {
      cnt++;
    }
  }
  int Myleaf;
  if (cnt == faid) {
    Myleaf = rt;
    for (auto u : leaf) {
      if (E[u][0].first != center && E[u][0].second > faid) {
        rt = u;
        break;
      }
    }
  } else {
    Myleaf = -1;
    function<void(int, int)> init = [&](int u, int fa) {
      for (auto [v, id] : E[u]) {
        if (v == fa) {
          if (fa != center && u != center && id < faid) {
            Myleaf = u;
          }
          continue;
        }
        init(v, u);
      }
    };
    init(rt, rt);
  }
  vector<int> fa(n, -1);
  vector<pair<int, int>> ans(n - 1);
  function<void(int)> dfs = [&](int u) {
    int id_fa = -1;
    for (auto [v, id] : E[u]) {
      if (v == fa[u]) {
        id_fa = id;
        continue;
      }
      fa[v] = u;
      dfs(v);
    }
    if (u == rt)
      return;
    if (fa[u] == rt) {
      ans[id_fa] = {u, Myleaf};
    } else {
      ans[id_fa] = {u, rt};
    }
  };
  dfs(rt);
  for (auto [u, v] : ans) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
}