#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> p(n), in(n);
  for (auto &i : p) {
    cin >> i;
  }
  vector<vector<int>> E(n), revE(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v); // u earlier than v
    in[u]++;
    revE[v].emplace_back(u);
  }
  vector<int> id(n + 1), pos(n);
  function<void(int)> cal = [&](int x) {
    auto deg = in;
    fill(id.begin(), id.end(), 0);
    fill(pos.begin(), pos.end(), 0);
    priority_queue<pair<int, int>> Q;
    for (int i = 0; i < n; ++i) {
      if (in[i] == 0) { // nobody after point i
        Q.emplace(i != x, i);
      }
    }
    /**
     * @brief Observation: When we visit u, all points no relation with u has
     * been calculated and they are arranged at the latest time. Then we assume
     * the min(pos[v]) in which v is after u is the earliest solution for all
     * assignment / only solution for such arragement. Why? Because if we want
     * to put u at an earlier point, it should be instead of some point has no
     * relation with u. But all points with no relation with u has been arranged
     * at the latest point through greedy. Thus, it's the solution.
     */
    while (!Q.empty()) {
      auto [_, u] = Q.top();
      Q.pop();
      int lst = p[u];
      for (auto v : E[u]) {
        // v is after u. The latest time of u should be min of v-1
        lst = min(lst, pos[v] - 1);
      }
      while (id[lst])
        lst--;
      assert(lst > 0);
      // avaliable time slot
      pos[u] = lst, id[lst] = 1;
      if (u == x) {
        cout << pos[x] << " ";
        return;
      }
      for (auto v : revE[u]) {
        deg[v]--;
        if (deg[v] == 0) {
          Q.emplace(v != x, v);
        }
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    cal(i);
  }
  cout << "\n";
}