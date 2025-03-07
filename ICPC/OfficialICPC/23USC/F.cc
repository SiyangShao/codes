#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
array<string, 3> c;
array<char, 3> name;
vector<string> ans;
auto swp(int i, int j, int pos_i, int pos_j) {
  // step 1: move pos_i to pos 1
  int x = pos_i - 0;
  if (x != 0) {
    string s = name[i] + to_string(10 - x);
    ans.emplace_back(s);
  }
  // step 2: move pos_j to pos 4
  int y = pos_j - 3;
  if (y < 0) {
    y += 10;
  }
  if (y != 0) {
    string s = name[j] + to_string(10 - y);
    ans.emplace_back(s);
  }
  if ((i + 1) % 3 == j) {
    ans.emplace_back("c2");
  } else {
    ans.emplace_back("c1");
  }
  {
    string s = name[j] + to_string(9);
    ans.emplace_back(s);
  }
  if ((i + 1) % 3 == j) {
    ans.emplace_back("c1");
  } else {
    ans.emplace_back("c2");
  }
  // affect for i:
  string new_i = c[i];
  for (int p = 0; p < 10; ++p) {
    new_i[p] = c[i][(p + x) % 10];
  }
  // affect for j:
  string new_j = c[j];
  for (int p = 0; p < 10; ++p) {
    new_j[p] = c[j][(p + y) % 10];
  }
  // swap
  for (int p = 0; p < 3; ++p) {
    swap(new_i[p], new_j[p]);
  }
  // go forward 1 for j
  string new_new_j = new_j;
  for (int p = 0; p < 10; ++p) {
    new_new_j[p] = new_j[(p + 1) % 10];
  }
  // swap back
  for (int p = 0; p < 3; ++p) {
    swap(new_i[p], new_new_j[p]);
  }
  // place
  c[i] = new_i;
  c[j] = new_new_j;
  dbg(i, j, c[i], c[j]);
}
auto solve() {
  name = {'o', 'g', 'r'};
  for (auto &i : c)
    cin >> i;
  while (true) {
    int pos_i = -1, pos_j = -1;
    for (int i = 0; i < 10; ++i) {
      if (c[0][i] == 'r') {
        pos_i = i;
        break;
      }
    }
    for (int i = 0; i < 10; ++i) {
      if (c[2][i] != 'r') {
        pos_j = i;
        break;
      }
    }
    if (pos_i != -1 && pos_j != -1) {
      swp(0, 2, pos_i, pos_j);
    } else {
      break;
    }
  }
  while (true) {
    int pos_i = -1, pos_j = -1;
    for (int i = 0; i < 10; ++i) {
      if (c[1][i] == 'r') {
        pos_i = i;
        break;
      }
    }
    for (int i = 0; i < 10; ++i) {
      if (c[2][i] != 'r') {
        pos_j = i;
        break;
      }
    }
    if (pos_i != -1 && pos_j != -1) {
      swp(1, 2, pos_i, pos_j);
    } else {
      break;
    }
  }
  while (true) {
    int pos_i = -1, pos_j = -1;
    for (int i = 0; i < 10; ++i) {
      if (c[0][i] == 'g') {
        pos_i = i;
        break;
      }
    }
    for (int i = 0; i < 10; ++i) {
      if (c[1][i] != 'g') {
        pos_j = i;
        break;
      }
    }
    if (pos_i != -1 && pos_j != -1) {
      swp(0, 1, pos_i, pos_j);
    } else {
      break;
    }
  }
  cout << ans.size() << '\n';
  for (auto &i : ans) {
    cout << i << '\n';
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