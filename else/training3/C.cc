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
  int n, m;
  cin >> n >> m;
  unordered_map<string, int> mp;
  mp["?"] = n;
  vector<tuple<int, int, int>> res(n);
  vector<vector<int>> record(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    mp[s] = i;
    string sym;
    cin >> sym;
    string a, b;
    cin >> a;
    if (mp.contains(a)) {
      cin >> sym;
      cin >> b;
      int x = mp[a], y = mp[b];
      int z = 0;
      if (sym == "AND") {
        z = 1;
      } else if (sym == "OR") {
        z = 2;
      } else {
        z = 3;
      }
      res[i] = tuple<int, int, int>{x, z, y};

    } else {
      for (int j = 0; j < m; ++j) {
        record[i][j] = a[j] - '0';
      }
      dbg(record[i]);
      res[i] = tuple<int, int, int>{i, 0, i};
    }
  }
  vector<int> mx(m), mi(m);
  for (int pos = 0; pos < m; ++pos) {
    vector<int> one(n + 1, 0), zero(n + 1, 0);
    one[n] = 1, zero[n] = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
      auto [a, op, b] = res[i];
      if (op == 0) {
        one[i] = record[i][pos];
        zero[i] = record[i][pos];
      } else if (op == 1) {
        one[i] = one[a] & one[b];
        zero[i] = zero[a] & zero[b];
      } else if (op == 2) {
        one[i] = one[a] | one[b];
        zero[i] = zero[a] | zero[b];
      } else {
        one[i] = one[a] ^ one[b];
        zero[i] = zero[a] ^ zero[b];
      }
      dbg(one[i], zero[i]);
      x += one[i], y += zero[i];
    }
    dbg(x, y);
    if (x == y) {
      mx[pos] = 0;
      mi[pos] = 0;
    } else if (x < y) {
      mx[pos] = 0;
      mi[pos] = 1;
    } else {
      mx[pos] = 1;
      mi[pos] = 0;
    }
  }
  for (auto i : mi) {
    cout << i;
  }
  cout << "\n";
  for (auto i : mx) {
    cout << i;
  }
  cout << "\n";
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