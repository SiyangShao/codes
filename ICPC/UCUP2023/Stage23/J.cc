#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 2510;
int n;
array<int, N> d, cur, vis, fa;
array<array<int, N>, N> mp;
void init() {
  for (int i = 1; i <= n; ++i) {
    cur[i] = 0;
    vis[i] = 0;
    for (int j = 1; j <= d[i]; ++j) {
      mp[i][j] = 0;
    }
    d[i] = 0;
    fa[i] = 0;
  }
  n = 0;
}
void go(int edg) {
  cout << "> " << edg << "\n";
  cout.flush();
}
void pos(int from, bool flag = false) {
  int u;
  cin >> u;
  if (flag)
    mp[from][cur[from]] = u;
  n = max(n, u);
  cin >> d[u];
  dbg(u, cur[u], d[u]);
  if (cur[u] < d[u]) {
    // 随机游走
    // go ++cur[u]
    go(++cur[u]);
    pos(u, true);
    return;
  }
  // all edges have been walked.
  dbg(u, "随机游走");
  vis[u] = 1;
  for (int id = 1; id <= d[u]; ++id) {
    dbg(u, "走到", mp[u][id]);
    if (vis[mp[u][id]])
      continue;
    fa[mp[u][id]] = u;
    go(id);
    pos(u);
  }
  for (int id = 1; id <= d[u]; ++id) {
    if (mp[u][id] == fa[u]) {
      dbg(u, "回归", mp[u][id]);
      go(id);
      int noneedx, noneedy;
      cin >> noneedx >> noneedy;
      assert(mp[u][id] == noneedx);
      cout.flush();
      return;
    }
  }
}
auto solve() {
  init();
  pos(-1);
  vector<pair<int, int>> edg;
  for (int u = 1; u <= n; ++u) {
    for (int j = 1; j <= d[u]; ++j) {
      int v = mp[u][j];
      if (u < v)
        edg.emplace_back(u, v);
    }
  }
  cout.flush();
  cout << "! ";
  for (auto [u, v] : edg) {
    cout << u << " " << v << " ";
  }
  cout << "\n";
  cout.flush();
  string CORRECT;
  cin >> CORRECT;
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