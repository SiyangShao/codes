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
  vector<int> ax(n), ay(n);
  for (auto &i : ax)
    cin >> i;
  for (auto &i : ay)
    cin >> i;
  int m;
  cin >> m;
  vector<int> bx(m), by(m);
  for (auto &i : bx)
    cin >> i;
  for (auto &i : by)
    cin >> i;
  vector<int> aid(n), bid(m);
  iota(aid.begin(), aid.end(), 0);
  iota(bid.begin(), bid.end(), 0);
  vector<vector<int>> E(n + m);
  sort(aid.begin(), aid.end(), [&](int i, int j) { return ay[i] > ay[j]; });
  sort(bid.begin(), bid.end(), [&](int i, int j) { return bx[i] > bx[j]; });
  auto itb = bid.begin();
  int maximumHealth = 0, maximumHealthID = -1;
  for (auto i : aid) {
    while (itb != bid.end() && bx[*itb] > ay[i]) {
      if (by[*itb] > maximumHealth) {
        maximumHealth = by[*itb];
        maximumHealthID = *itb;
      }
      itb++;
    }
    if (maximumHealthID != -1) {
      E[i].emplace_back(maximumHealthID + n);
    }
  }
  sort(aid.begin(), aid.end(), [&](int i, int j) { return ax[i] > ax[j]; });
  sort(bid.begin(), bid.end(), [&](int i, int j) { return by[i] > by[j]; });
  auto ita = aid.begin();
  maximumHealth = 0, maximumHealthID = -1;
  for (auto i : bid) {
    while (ita != aid.end() && ax[*ita] > by[i]) {
      if (ay[*ita] > maximumHealth) {
        maximumHealth = ay[*ita];
        maximumHealthID = *ita;
      }
      ita++;
    }
    if (maximumHealthID != -1) {
      E[i + n].emplace_back(maximumHealthID);
    }
  }
  vector<int> vis(n + m, -1), in_stack(n + m, 0);
  function<void(int)> dfs = [&](int u) {
    in_stack[u] = 1;
    if (E[u].empty()) {
      vis[u] = 1; // win
      in_stack[u] = 0;
      return;
    }
    int loose = 0, win = 0, stk = 0;
    for (auto v : E[u]) {
      if (!in_stack[v]) {
        if (vis[v] == -1) {
          dfs(v);
        }
        if (vis[v] == 0) {
          loose++;
        } else if (vis[v] == 1) {
          win++;
        } else {
          stk++;
        }
      } else {
        stk++;
      }
    }
    if (win != 0) {
      vis[u] = 0;
    } else if (stk != 0) {
      vis[u] = 2;
    } else {
      assert(loose != 0);
      vis[u] = 1;
    }
    in_stack[u] = 0;
    return;
  };
  for (int i = 0; i < n + m; ++i) {
    if (vis[i] == -1)
      dfs(i);
  }
  int win = 0, loose = 0, draw = 0;
  for (int i = 0; i < n; ++i) {
    if (vis[i] == 0)
      loose++;
    else if (vis[i] == 1)
      win++;
    else
      draw++;
  }
  cout << win << " " << draw << " " << loose << "\n";
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