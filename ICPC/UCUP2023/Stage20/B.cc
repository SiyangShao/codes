#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
int getBit(int x, int pos) { return (x / pos) % 3; }
auto solve() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (auto &i : s) {
    cin >> i;
  }
  int N = 1;
  for (int i = 0; i < 12; ++i) {
    N *= 3;
  }
  vector<vector<int>> E(N);
  for (auto u : s) {
    vector<int> bit(12);
    int cur = 1;
    for (int i = 0; i < 12; ++i) {
      bit[i] = (u / cur) % 3;
      cur = cur * 3;
    }
    cur = 1;
    for (int i = 0; i < 12; ++i) {
      for (int j = 0; j < bit[i]; ++j) {
        int v = u - cur * bit[i] + cur * j;
        E[u].emplace_back(v);
      }
      cur *= 3;
    }
  }
  for (int u = 0; u < N; ++u) {
    vector<int> bit(12);
    int cur = 1;
    for (int i = 0; i < 12; ++i) {
      bit[i] = (u / cur) % 3;
      cur = cur * 3;
    }
    cur = 1;
    for (int i = 0; i < 12; ++i) {
      for (int j = bit[i] + 1; j < 3; ++j) {
        int v = u - cur * bit[i] + cur * j;
        E[u].emplace_back(v);
      }
      cur *= 3;
    }
  }
  queue<int> Q;
  vector<int> vis(N);
  Q.emplace(s[0]);
  vis[s[0]] = 1;
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      Q.emplace(v);
      vis[v] = 1;
    }
  }
  if (vis[s[n - 1]])
    cout << "YES\n";
  else
    cout << "NO\n";
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