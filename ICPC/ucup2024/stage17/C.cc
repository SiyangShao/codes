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
  n--;
  vector<string> ans;
  vector<tuple<int, int, int, int>> debg;
  vector<int> op;
  while (n) {
    if (n % 4 == 2) {
      op.emplace_back(1);
      n = (n - 2) / 2;
    } else {
      op.emplace_back(0);
      n -= 2;
    }
  }
  if (!op.empty())
    reverse(op.begin(), op.end());
  int cur_id = 1;
  for (auto i : op) {
    if (i == 0) {
      string s = "POP " + to_string(cur_id) + " GOTO " + to_string(cur_id + 1) +
                 "; PUSH " + to_string(cur_id) + " GOTO " + to_string(cur_id);
      ans.emplace_back(s);
      debg.emplace_back(cur_id, cur_id + 1, cur_id, cur_id);
    } else {
      string s = "POP " + to_string(cur_id) + " GOTO " + to_string(cur_id + 1) +
                 "; PUSH " + to_string(cur_id) + " GOTO 1";
      ans.emplace_back(s);
      debg.emplace_back(cur_id, cur_id + 1, cur_id, 1);
    }
    cur_id++;
  }
  ans.emplace_back("HALT; PUSH 1 GOTO 1");
  debg.emplace_back(-1, -1, -1, -1);
  assert(ans.size() <= 64);
  // for (auto [a, b, c, d] : debg) {
  //   cout << a << " " << b << " " << c << " " << d << "\n";
  // }
  cout << ans.size() << "\n";
  for (auto &i : ans) {
    cout << i << "\n";
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