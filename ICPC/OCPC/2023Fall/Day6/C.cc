#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
void build(vector<vector<int>> &E, vector<int> &size, int u) {
  if (E[u].empty()) {
    size[u] = 1;
    return;
  }
  for (auto v : E[u]) {
    build(E, size, v);
    size[u] += size[v];
  }
}
struct DSU {
  vector<int> fa;
  DSU(int n) : fa(n) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
stack<int> st;
void dfs(int u, vector<set<int>> &E) {
  while (!E[u].empty()) {
    int v = *E[u].begin();
    E[u].erase(v), E[v].erase(u);
    dfs(v, E);
  }
  st.emplace(u);
}
pair<bool, vector<int>> check(vector<int> &node, vector<set<int>> &E, int k,
                              int n, int m) {
  if (node.empty()) {
    return {true, {}};
  }
  while (!st.empty())
    st.pop();
  int u = -1, v = -1, start = node[0];
  for (auto i : node) {
    if (i >= k) {
      start = i;
    }
    if (E[i].size() % 2 == 1) {
      if (u == -1) {
        u = i;
      } else if (v == -1) {
        v = i;
      } else {
        return {false, {}};
      }
    }
  }
  if (u != -1 && u != n - 1 && u != n + m - k - 1) {
    return {false, {}};
  }
  if (u == -1)
    u = start;
  dfs(u, E);
  vector<int> vec;
  while (!st.empty()) {
    vec.emplace_back(st.top());
    st.pop();
  }
  return {true, vec};
}
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n - 1), q(m - 1);
  vector<vector<int>> En(n), Em(m);
  vector<int> sizen(n), sizem(m);
  for (auto &i : p) {
    cin >> i;
    i--;
  }
  for (int i = 0; i + 1 < n; ++i) {
    En[p[i]].emplace_back(i);
  }
  for (auto &i : q) {
    cin >> i;
    i--;
  }
  for (int i = 0; i + 1 < m; ++i) {
    Em[q[i]].emplace_back(i);
  }
  build(En, sizen, n - 1);
  build(Em, sizem, m - 1);
  int k = 0;
  while (k + 1 < min(n, m)) {
    if (!En[k].empty() || !Em[k].empty()) {
      break;
    }
    k++;
  }
  vector<set<int>> E(n + m - k);

  DSU dsu(n + m - k);
  for (int u = k; u < n; ++u) {
    for (auto v : En[u]) {
      if (sizen[v] % 2 == 0)
        continue;
      E[u].emplace(v);
      E[v].emplace(u);
      dsu.merge(u, v);
    }
  }
  for (int i = k; i < m; ++i) {
    int u = i - k + n;
    for (auto v : Em[i]) {
      if (sizem[v] % 2 == 0)
        continue;
      if (v >= k) {
        v = v - k + n;
      }
      E[u].emplace(v);
      E[v].emplace(u);
      dsu.merge(u, v);
    }
  }
  vector<vector<int>> node(n + m - k);
  for (int i = 0; i < n + m - k; ++i) {
    node[dsu.find(i)].emplace_back(i);
  }
  for (int i = 0; i < k; ++i) {
    assert(E[i].size() == 2);
  }
  dbg(k);
  dbg(node);
  vector<int> col(k);
  for (int i = 0; i < n + m - k; ++i) {
    auto [flag, vec] = check(node[i], E, k, n, m);
    if (!flag) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    for (int j = 0; j < (int)vec.size(); ++j) {
      // cout << vec[j] << " ";
      if (vec[j] < k) {
        int prev = j - 1;
        if (j == 0) {
          prev = (int)vec.size() - 1;
        }
        prev = vec[prev];
        if (prev < n) {
          col[vec[j]] = 1;
        }
      }
    }
    // cout << "\n";
  }
  for (int i = 0; i < k; ++i) {
    if (col[i])
      cout << "R";
    else
      cout << "B";
  }
  cout << "\n";
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