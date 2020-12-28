// 这龙鳞 却曾经 铿锵落地犹如碎冰
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
  int n, k, m;
  cin >> n >> k >> m;
  string s;
  cin >> s;
  vector<int> num(k), del(k);
  for (auto i : s) {
    num[i - 'a']++;
  }
  for (int i = 0; i < k; ++i) {
    if (num[i] < n) {
      cout << "NO\n";
      for (int j = 0; j < n; ++j) {
        cout << char(i + 'a');
      }
      cout << "\n";
      return;
    }
  }
  reverse(s.begin(), s.end());
  int delNum = 0, len = n;
  vector<char> lst;
  for (auto i : s) {
    if (del[i - 'a'] == 0)
      delNum++;
    del[i - 'a'] = 1;
    num[i - 'a']--;
    if (delNum == k) {
      lst.emplace_back(i);
      fill(del.begin(), del.end(), 0);
      delNum = 0;
      len--;
      if (len == 0)
        break;
      for (int j = 0; j < k; ++j) {
        if (num[j] < len) {
          cout << "NO\n";
          for (int x = 0; x < len; ++x) {
            cout << char(j + 'a');
          }
          reverse(lst.begin(), lst.end());
          for (auto x : lst) {
            cout << x;
          }
          cout << "\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
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