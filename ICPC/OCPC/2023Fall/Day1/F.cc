#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n), in(n);
  for (auto &i : a) {
    cin >> i;
    i--;
    in[i]++;
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n; ++i) {
    E[a[i]].emplace_back(i);
  }
  stack<int> sttmp;
  vector<int> in_st(n), vis(n);
  int circle_num = 0;
  vector<int> in_which_circle(n, -1), circle(n), in_circle(n);
  function<void(int)> dfs = [&](int u) {
    in_st[u] = 1;
    vis[u] = 1;
    sttmp.emplace(u);
    if (!vis[a[u]]) {
      dfs(a[u]);
    } else {
      if (in_st[a[u]]) {
        int cnt = 0;
        while (sttmp.top() != a[u]) {
          in_which_circle[sttmp.top()] = circle_num;
          in_st[sttmp.top()] = 0;
          in_circle[sttmp.top()] = 1;
          cnt++;
          sttmp.pop();
        }
        in_which_circle[sttmp.top()] = circle_num;
        in_st[sttmp.top()] = 0;
        in_circle[sttmp.top()] = 1;
        sttmp.pop();
        cnt++;
        circle[circle_num] = cnt;
        while (!sttmp.empty()) {
          in_st[sttmp.top()] = 0;
          in_which_circle[sttmp.top()] = circle_num;
          sttmp.pop();
        }
        circle_num++;
        return;
      } else {
        while (!sttmp.empty()) {
          assert(in_which_circle[a[u]] != -1);
          in_st[sttmp.top()] = 0;
          in_which_circle[sttmp.top()] = in_which_circle[a[u]];
          sttmp.pop();
        }
        return;
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0) {
      dfs(i);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (in_which_circle[i] == -1) {
      dfs(i);
    }
  }
  vector<int> allSize;
  vector<int> dep(n);
  function<void(int)> long_chain = [&](int u) {
    dep[u] = 1;
    int hson = -1;
    for (auto v : E[u]) {
      long_chain(v);
      if (dep[v] + 1 > dep[u]) {
        dep[u] = dep[v] + 1;
        hson = v;
      }
    }
    for (auto v : E[u]) {
      if (v != hson) {
        allSize.emplace_back(dep[v]);
      }
    }
  };
  vector<vector<int>> chains(circle_num);
  for (int i = 0; i < n; ++i) {
    if (in_circle[i] == 0 && in_circle[a[i]] == 1) {
      long_chain(i);
      chains[in_which_circle[i]].emplace_back(dep[i]);
    }
  }
  vector<int> presum(n + 5, 0);
  for (int i = 0; i < circle_num; ++i) {
    presum[circle[i]]++;
    chains[i].emplace_back(0);
    sort(chains[i].begin(), chains[i].end(), greater<>());
    presum[circle[i] + chains[i][0] + 1]--;
    allSize.emplace_back(circle[i] + chains[i][0]);
    for (int j = 1; j < (int)chains[i].size(); ++j) {
      allSize.emplace_back(chains[i][j]);
    }
  }
  sort(allSize.begin(), allSize.end(), greater<>());
  for (int i = 1; i < (int)allSize.size(); ++i) {
    allSize[i] += allSize[i - 1];
  }
  int cur = 0;
  for (int i = 1; i <= n; ++i) {
    cur += presum[i];
    if (cur > 0) {
      cout << 0;
    } else {
      auto it = lower_bound(allSize.begin(), allSize.end(), i);
      cout << max((int)(it - allSize.begin()), 1);
    }
    if (i != n) {
      cout << " ";
    }
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