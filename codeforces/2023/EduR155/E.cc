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
  vector<int> fa(n);
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    cin >> fa[i];
    fa[i]--;
    E[fa[i]].emplace_back(i);
  }
  // Case 1: 1
  if (static_cast<int>(E[0].size()) == n - 1) {
    cout << 1 << endl;
    for (int i = 1; i < n; ++i) {
      cout << 1 << " ";
    }
    cout << endl;
    int zero;
    cin >> zero;
    int num;
    cin >> num;
    cout << 1 << endl;
    int sth;
    cin >> sth;
    return;
  }
  // Case 2
  function<bool()> try_two = [&]() {
    vector<int> col(n, -1);
    function<bool(int)> dfs = [&](int u) {
      if (static_cast<int>(E[u].size()) == 1) {
        if (col[u] != 0) {
          return false;
        }
        col[E[u][0]] = 1;
        return dfs(E[u][0]);
      }
      bool flag = true;
      for (auto v : E[u]) {
        col[v] = 1 ^ col[u];
        flag = flag and dfs(v);
      }
      return flag;
    };
    for (auto u : E[0]) {
      col[u] = 0;
      if (dfs(u))
        continue;
      col[u] = 1;
      if (dfs(u))
        continue;
      return false;
    }
    cout << 2 << endl;
    for (int i = 1; i < n; ++i) {
      cout << col[i] + 1 << " ";
    }
    cout << endl;
    int op;
    while (cin >> op) {
      if (op == 1)
        return true;
      if (op == -1)
        return true;
      int x, y;
      cin >> x >> y;
      if (x == 1) {
        cout << "1" << endl;
      } else {
        cout << "2" << endl;
      }
    }
    return true;
  };

  if (try_two())
    return;
  // Case 3: 3
  vector<int> col(n);
  function<void(int, int)> dfs = [&](int u, int c) {
    col[u] = c;
    for (auto v : E[u]) {
      dfs(v, (c + 1) % 3);
    }
  };
  dfs(0, 0);
  cout << 3 << endl;
  for (int i = 1; i < n; ++i) {
    cout << col[i] + 1 << " ";
  }
  cout << endl;
  int op;
  while (cin >> op) {
    if (op == 1) {
      return;
    }
    if (op == -1) {
      return;
    }
    int r, g, b;
    cin >> r >> g >> b;
    assert(r == 0 || g == 0 || b == 0);
    assert(!(r == 0 && g == 0 && b == 0));
    if (r == 0 && g != 0) {
      cout << 2 << endl;
    } else if (g == 0 && b != 0) {
      cout << 3 << endl;
    } else {
      assert(b == 0 && r != 0);
      cout << 1 << endl;
    }
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