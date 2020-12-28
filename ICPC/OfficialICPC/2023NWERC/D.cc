#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ld = double;
constexpr ld myR = numbers::pi * 2.5;
auto solve() {
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for (auto &i : mp)
    cin >> i;
  int nodeNum = (h + 1) * (w + 1) + (h + 1) * w + (w + 1) * h;
  vector<vector<pair<int, ld>>> E(nodeNum);
  auto LeftUp = [&](int i, int j) { return i * (w + 1) + j; };
  auto RightUp = [&](int i, int j) { return LeftUp(i, j) + 1; };
  auto LeftDown = [&](int i, int j) { return (i + 1) * (w + 1) + j; };
  auto RightDown = [&](int i, int j) { return LeftDown(i, j) + 1; };
  auto Top = [&](int i, int j) { return (h + 1) * (w + 1) + i * w + j; };
  auto Down = [&](int i, int j) { return Top(i, j) + w; };
  auto Left = [&](int i, int j) {
    return (h + 1) * (w + 1) + (h + 1) * w + i * (w + 1) + j;
  };
  auto Right = [&](int i, int j) { return Left(i, j) + 1; };
  auto addEdge = [&](int u, int v, ld len) {
    E[u].emplace_back(v, len);
    E[v].emplace_back(u, len);
  };
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      addEdge(LeftUp(i, j), Top(i, j), 5);
      addEdge(LeftUp(i, j), Left(i, j), 5);
      addEdge(RightUp(i, j), Right(i, j), 5);
      addEdge(RightUp(i, j), Top(i, j), 5);
      addEdge(LeftDown(i, j), Left(i, j), 5);
      addEdge(LeftDown(i, j), Down(i, j), 5);
      addEdge(RightDown(i, j), Right(i, j), 5);
      addEdge(RightDown(i, j), Down(i, j), 5);
      if (mp[i][j] == 'O') {
        addEdge(Top(i, j), Left(i, j), myR);
        addEdge(Top(i, j), Right(i, j), myR);
        addEdge(Down(i, j), Left(i, j), myR);
        addEdge(Down(i, j), Right(i, j), myR);
      }
    }
  }
  vector<int> vis(nodeNum);
  constexpr ld inf = 1e16;
  vector<ld> dis(nodeNum, inf);
  priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<>> Q;
  dis[LeftUp(0, 0)] = 0;
  Q.emplace(0, LeftUp(0, 0));
  while (!Q.empty()) {
    auto [_, u] = Q.top();
    Q.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto [v, len] : E[u]) {
      if (dis[v] > dis[u] + len) {
        dis[v] = dis[u] + len;
        Q.emplace(dis[v], v);
      }
    }
  }
  cout << fixed << setprecision(16) << dis[RightDown(h - 1, w - 1)] << "\n";
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