#include <bits/stdc++.h>
#include <chrono>
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
vector<int> Hierholzer(vector<set<int>> &E, int start) {
  vector<int> ans;
  stack<int> st;
  st.emplace(start);
  while (!st.empty()) {
    auto u = st.top();
    if (E[u].empty()) {
      st.pop();
      ans.emplace_back(u);
    } else {
      int v = *E[u].begin();
      E[v].erase(u);
      E[u].erase(v);
      st.emplace(v);
    }
  }
  return ans;
}
vector<vector<int>> Hier(vector<set<int>> &E) {
  vector<bool> vis(E.size(), false);
  vector<vector<int>> ans;
  for (int i = 0; i < (int)E.size(); ++i) {
    if (E[i].size() % 2 == 1 && !vis[i]) {
      auto tmp = Hierholzer(E, i);
      ans.emplace_back(tmp);
      for (auto j : tmp) {
        vis[j] = true;
      }
    }
  }
  for (int i = 0; i < (int)E.size(); ++i) {
    if (!vis[i]) {
      auto tmp = Hierholzer(E, i);
      tmp.pop_back();
      ans.emplace_back(tmp);
      for (auto j : tmp) {
        vis[j] = true;
      }
    }
  }
  return ans;
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
    if (sizen[k] != 1 || sizem[k] != 1) {
      break;
    }
    k++;
  }
  vector<set<int>> E(n + m - k);
  for (int u = 0; u < n; ++u) {
    for (auto v : En[u]) {
      if (sizen[v] % 2 == 0)
        continue;
      E[u].emplace(v);
      E[v].emplace(u);
    }
  }
  for (int i = 0; i < m; ++i) {
    int u = (i < k ? i : i - k + n);
    for (auto v : Em[i]) {
      if (sizem[v] % 2 == 0)
        continue;
      E[u].emplace(v);
      E[v].emplace(u);
    }
  }
  auto ans = Hier(E);
  dbg(ans);
  vector<int> col(k);
  for (auto &i : ans) {
    for (int j = 0; j < (int)i.size(); ++j) {
      int nxt = i[(j + 1) % i.size()];
      if (nxt < k) {
        if (i[j] < n) {
          col[nxt] = 1;
        }
      }
    }
  }
  for (auto i : col) {
    if (i)
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