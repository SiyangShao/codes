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
  vector<vector<int>> E(n * 2);
  map<pair<int, int>, int> col;
  for (int i = 0; i < 2 * n; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    E[x].emplace_back(y + n);
    E[y + n].emplace_back(x);
    col[{x, y + n}] = col[{y + n, x}] = i;
  }
  vector<int> vis(n * 2), fa(n * 2, -1);
  vector<int> circle;
  function<bool(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (auto v : E[u]) {
      if (!vis[v]) {
        fa[v] = u;
        if (dfs(v)) {
          return true;
        }
      } else if (v != fa[u]) {
        int cur = u;
        while (cur != v) {
          circle.emplace_back(cur);
          cur = fa[cur];
        }
        circle.emplace_back(v);
        return true;
      }
    }
    return false;
  };
  for (int i = 0; i < 2 * n; ++i) {
    if (vis[i])
      continue;
    if (dfs(i)) {
      break;
    }
  }
  assert((int)circle.size() >= 4);
  dbg(circle);
  function<void(int, int)> ask = [&](int x, int y) {
    if (x > y)
      swap(x, y);
    cout << "? " << x + 1 << " " << y - n + 1 << endl;
  };
  reverse(circle.begin(), circle.end());
  dbg(col);
  dbg(circle);
  while ((int)circle.size() > 4) {
    int m = (int)circle.size();
    int half = m / 4;
    int x = circle[half], y = circle[m - 1 - half];
    ask(x, y);
    int c;
    cin >> c;
    c--;
    col[{x, y}] = col[{y, x}] = c;
    bool flag = false;
    vector<int> nxt;
    nxt.emplace_back(circle[half]);
    for (int i = half; i < m - 1 - half; ++i) {
      nxt.emplace_back(circle[i + 1]);
      if (col[{circle[i], circle[i + 1]}] == c) {
        nxt.clear();
        flag = true;
        break;
      }
    }
    dbg(flag);
    if (flag) {
      for (int i = 0; i <= half; ++i) {
        nxt.emplace_back(circle[i]);
      }
      for (int i = m - 1 - half; i < m; ++i) {
        nxt.emplace_back(circle[i]);
      }
    }
    dbg(nxt);
    swap(nxt, circle);
  }
  cout << "! ";
  int m = (int)circle.size();
  assert(m == 4);
  if (circle[0] >= n) {
    reverse(circle.begin(), circle.end());
  }
  cout << circle[0] + 1 << " " << circle[2] + 1 << " " << circle[1] - n + 1
       << " " << circle[3] - n + 1 << endl;
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
    string s;
    cin >> s;
    if (s == "OK")
      continue;
    return 0;
  }
}