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
  string s;
  cin >> s;
  vector<int> fa(n);
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    cin >> fa[i];
    fa[i]--;
    E[fa[i]].emplace_back(i);
  }
  vector<deque<int>> pos(n), neg(n);
  vector<int> zero(n), black(n);
  vector<int> ans(n);
  auto getTop = [&](int u) {
    if (neg[u].empty() && zero[u] == 0 && pos[u].empty()) {
      return pair{false, 0};
    }
    if (!neg[u].empty()) {
      pair<bool, int> val = {true, neg[u].front()};
      neg[u].pop_front();
      return val;
    }
    if (zero[u] != 0) {
      zero[u]--;
      return pair{true, 0};
    }
    pair<bool, int> val = {true, pos[u].front()};
    pos[u].pop_front();
    return val;
  };
  function<void(int)> dfs = [&](int u) {
    if (s[u] == '1')
      black[u] = 1;
    int len = n + 1, nxt = -1;
    for (auto v : E[u]) {
      dfs(v);
      if (len > zero[v] + (int)pos[v].size() + (int)neg[v].size()) {
        len = zero[v] + (int)pos[v].size() + (int)neg[v].size();
        nxt = v;
      }
      black[u] += black[v];
    }
    ans[u] = 0;
    if (nxt != -1) {
      ans[u] = ans[nxt];
      swap(zero[u], zero[nxt]);
      swap(pos[u], pos[nxt]);
      swap(neg[u], neg[nxt]);
      deque<int> postmp, negtmp;
      int zerotmp = 0;
      for (auto v : E[u]) {
        if (v == nxt)
          continue;
        ans[u] = 0;
        while (true) {
          auto [flagx, valx] = getTop(u);
          auto [flagy, valy] = getTop(v);
          if (!flagx)
            break;
          assert(flagy);
          if (valx + valy < 0) {
            ans[u] += valx + valy;
            negtmp.emplace_back(valx + valy);
          } else if (valx + valy == 0) {
            zerotmp++;
          } else {
            postmp.emplace_back(valx + valy);
          }
        }
        assert(zero[u] == 0 && pos[u].empty() && neg[u].empty());
        swap(zero[u], zerotmp);
        swap(pos[u], postmp);
        swap(neg[u], negtmp);
      }
    }
    if (s[u] == '1')
      neg[u].emplace_back(-1), ans[u]--;
    else
      pos[u].emplace_front(1);
    dbg(u + 1, neg[u], pos[u], zero[u]);
  };
  dfs(0);
  for (int i = 0; i < n; ++i) {
    cout << black[i] + ans[i] << " ";
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