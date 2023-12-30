#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> E(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  vector<int> in(n);
  for (int i = 0; i < n; ++i) {
    E[a[i]].emplace_back(i);
    in[a[i]]++;
  }
  queue<int> Q;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0) {
      Q.emplace(i);
    }
  }
  vector<int> tag(n);
  vector<int> vis(n);
  while (!Q.empty()) {
    auto u = Q.front();
    vis[u] = 1;
    Q.pop();
    in[a[u]]--;
    bool flag = false;
    for (auto v : E[u]) {
      if (tag[v] == 1) {
        flag = true;
        break;
      }
    }
    if (flag) {
      tag[u] = 0;
    } else {
      tag[u] = 1;
    }
    if (in[a[u]] == 0) {
      Q.emplace(a[u]);
    }
  }
  vector<int> node;
  function<void(int, int)> dfs = [&](int u, int start) {
    vis[u] = 1;
    node.emplace_back(u);
    if (a[u] == start)
      return;
    dfs(a[u], start);
  };
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      node.clear();
      dfs(i, i);
      dbg(node);
      int start = -1;
      for (int j = 0; j < (int)node.size(); ++j) {
        for (auto v : E[node[j]]) {
          if (tag[v] == 1) {
            start = j;
            break;
          }
        }
        if (start != -1) {
          break;
        }
      }
      if (start == -1) {
        if (node.size() % 2 == 0) {
          for (int j = 0; j < (int)node.size(); ++j) {
            tag[node[j]] = j % 2;
          }
        } else {
          cout << "-1\n";
          return;
        }
        continue;
      }
      // ignore connection between last and first
      for (int j = start; j < start + (int)node.size(); ++j) {
        bool flag = false;
        int u = node[j % (int)node.size()];
        int pre = node[(j - 1 + (int)node.size()) % (int)node.size()];
        for (auto v : E[u]) {
          if (j == start && v == pre)
            continue;
          assert(tag[v] != -1);
          if (tag[v] == 1)
            flag = true;
        }
        if (flag)
          tag[u] = 0;
        else
          tag[u] = 1;
      }
      int cnt = 1;
      for (auto v : E[node[start]]) {
        if (tag[v] == 1) {
          cnt = 0;
          break;
        }
      }
      if (tag[node[start]] != cnt) {
        cout << "-1\n";
        return;
      }
    }
  }
  vector<int> ans;
  dbg(tag);
  for (int i = 0; i < n; ++i) {
    if (tag[i] == 1) {
      ans.emplace_back(a[i] + 1);
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
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