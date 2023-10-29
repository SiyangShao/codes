#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
void default_method() {
  cout << "5\n";
  cout << "RIGHT\n";
  cout << "IF-OPEN 5\n";
  cout << "LEFT\n";
  cout << "GOTO 2\n";
  cout << "FORWARD\n";
}
string translate(int i) {
  if (i <= 3) {
    return "GOTO " + to_string(i + 1);
  }
  if (i <= 7) {
    return "IF-OPEN " + to_string(i - 4 + 1);
  }
  if (i == 8) {
    return "FORWARD";
  }
  if (i == 9) {
    return "LEFT";
  }
  if (i == 10) {
    return "RIGHT";
  }
  return "null";
}
void outputOP(vector<int> &op) {
  for (auto i : op) {
    cout << translate(i) << "\n";
  }
}
vector<string> mp;
array<array<array<array<bool, 4>, 4>, 12>, 12> vis;
int n, m;
pair<int, int> S, G;
array dx = {1, 0, -1, 0}, dy = {0, -1, 0, 1};
bool check_pos(pair<int, int> p) {
  if (p.first < 0 || p.first >= n || p.second < 0 || p.second >= m)
    return false;
  return mp[p.first][p.second] == '.';
}
bool check_op(vector<int> &op) {
  int len = (int)op.size();
  for (auto i : op) {
    if (i <= 3 and i >= len)
      return false;
    if (i <= 7 and i > 3 and i - 4 >= len)
      return false;
  }
  return true;
}
bool check(vector<int> &op) {
  if (!check_op(op))
    return false;
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      for (int k = 0; k < 4; ++k) {
        for (int l = 0; l < 4; ++l) {
          vis[i][j][k][l] = false;
        }
      }
    }
  }
  pair<int, int> pos = S;
  int dir = 0;
  int id = 0;
  dbg(op);
  while (true) {
    if (pos == G)
      return true;
    dbg(dir, id);
    if (vis[pos.first][pos.second][dir][id])
      return false;
    vis[pos.first][pos.second][dir][id] = true;
    int nxt = op[id];
    if (nxt <= 3) {
      // goto
      id = nxt;
      continue;
    } else if (nxt <= 7) {
      // if open
      pair<int, int> nxt_pos = {pos.first + dx[dir], pos.second + dy[dir]};
      if (check_pos(nxt_pos)) {
        id = nxt - 4;
        continue;
      }
    } else if (nxt == 8) {
      pair<int, int> nxt_pos = {pos.first + dx[dir], pos.second + dy[dir]};
      if (check_pos(nxt_pos)) {
        pos = nxt_pos;
      }
    } else if (nxt == 10) {
      dir++;
      if (dir == 4)
        dir = 0;
    } else {
      // nxt == 9
      dir--;
      if (dir < 0)
        dir = 3;
    }
    id++;
    if (id >= (int)op.size())
      id = 0;
  }
}
vector<int> ans;
bool dfs(int len, vector<int> &op) {
  if (len == 0) {
    if (check(op)) {
      ans = op;
      return true;
    }
    return false;
  }
  for (int i = 0; i <= 10; ++i) {
    op.emplace_back(i);
    if (dfs(len - 1, op)) {
      return true;
    }
    op.pop_back();
  }
  return false;
}
auto solve() {
  cin >> n >> m;
  mp = vector<string>(n);
  for (auto &i : mp) {
    cin >> i;
  }
  for (int i = 0; i < m; ++i) {
    if (mp[0][i] == 'S') {
      S = {0, i};
      mp[0][i] = '.';
    }
    if (mp[n - 1][i] == 'G') {
      G = {n - 1, i};
      mp[n - 1][i] = '.';
    }
  }
  for (int len = 1; len <= 4; ++len) {
    vector<int> op;
    if (dfs(len, op)) {
      cout << len << "\n";
      outputOP(ans);
      return;
    }
  }

  default_method();
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