#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto transform(char s) {
  if (s == 'D')
    return 0;
  if (s == 'C')
    return 1;
  if (s == 'H')
    return 2;
  if (s == 'S')
    return 3;
  return -1;
}
auto solve() {
  int n;
  cin >> n;
  vector<string> card(n);
  vector<int> cnt(4, 0);
  for (auto &i : card) {
    cin >> i;
    cnt[transform(i[1])]++;
  }
  vector<int> op(6);
  for (auto &i : op)
    cin >> i;
  int base = 0, res = 0, add = 0;
  for (int i = 0; i < 4; ++i) {
    base += cnt[i] / 5;
    cnt[i] = cnt[i] % 5;
    res = res + cnt[i];
  }
  for (int i = 0; i < (1LL << 4); i++) {
    if (popcount((unsigned int)i) > res) {
      continue;
    }
    vector<int> need(4);
    for (int j = 0; j < 4; ++j) {
      need[j] = ((i >> j) & 1);
    }
    int ret = 0;
    for (int j = 0; j < 4; ++j) {
      if (!need[j]) {
        ret += cnt[j];
      }
    }
    auto used_op = op;
    bool possible = true;
    for (int j = 0; j < 4; ++j) {
      if (need[j]) {
        int nd = 5 - cnt[j];
        if (ret < nd) {
          possible = false;
          break;
        }
        ret -= nd;
        int choice = used_op[j] * 3;
        choice = min(choice, nd);
        nd -= choice;
        if (nd == 0) {
          continue;
        }
        if (nd == 5) {
          // use lovers first. Must use
          if (used_op[4] != 0) {
            used_op[4]--;
            nd--;
          } else {
            possible = false;
            break;
          }
        }
        // use death as much as possible
        choice = min(used_op[5], nd);
        nd -= choice;
        used_op[5] -= choice;
        // use lovers
        choice = min(used_op[4], nd);
        nd -= choice;
        used_op[4] -= choice;
        if (nd != 0) {
          possible = false;
          break;
        }
      }
    }
    if (possible) {
      add = max(add, popcount((unsigned int)i));
    }
  }
  cout << base + add << "\n";
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