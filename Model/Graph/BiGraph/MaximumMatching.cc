// n vertices left, m vertices right
#include <bits/stdc++.h>
using namespace std;
struct MaximumMatching {
  int n, m;
  vector<vector<int>> E;
  vector<int> vis, link;
  MaximumMatching(int _n, int _m) : n(_n), m(_m), E(_n), vis(_m), link(_m){};
  bool dfs(int u) {
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      vis[v] = 1;
      if (link[v] == -1 || dfs(link[v])) {
        link[v] = u;
        return true;
      }
    }
    return false;
  };
  void solve() {
    fill(link.begin(), link.end(), -1);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      // dfs(i) x times means add x points same as point i in the map
      if (dfs(i)) {
        fill(vis.begin(), vis.end(), 0);
        cnt++;
      }
    }
  }
};