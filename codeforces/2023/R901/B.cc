#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
int getBit(int msk, int k) { return (msk >> k) & 1; }
int transfer(int x, int op) {
  int a = getBit(x, 2), b = getBit(x, 1), m = getBit(x, 0);
  switch (op) {
  case 1:
    a = a & b;
    break;
  case 2:
    a = a | b;
    break;
  case 3:
    b = b ^ a;
    break;
  case 4:
    b = b ^ m;
    break;
  }
  return (a * 4 + b * 2 + m);
}
vector<int> dis(400000, -1);
array<int, 8> pw5;
int hashv(vector<int> &vec) {
  int ans = 0;
  for (int i = 0; i < 8; ++i) {
    int x = vec[i];
    int a = getBit(x, 2), b = getBit(x, 1);
    ans *= 4;
    ans += a * 2 + b;
  }
  return ans;
}
void init() {
  vector<int> status(8);
  pw5[0] = 1;
  for (int i = 0; i < 8; ++i) {
    status[i] = i;
    if (i != 0)
      pw5[i] = pw5[i - 1] * 5;
  }
  queue<pair<vector<int>, int>> Q;
  Q.emplace(status, 0);
  set<int> st;
  st.emplace(hashv(status));
  while (!Q.empty()) {
    const auto [vec, d] = Q.front();
    Q.pop();
   
    for (int i = 0; i < 256; ++i) {
      int ans = 0;
      for (int j = 0; j < 8; ++j) {
        int cur = vec[j] / 2;
        if ((i >> j) & 1) {
          ans += cur * pw5[j];
        } else {
          ans += 4 * pw5[j];
        }
      }
      if (dis[ans] == -1) {
        dis[ans] = d;
      }
    }
    vector<int> nxt(8, 0);
    for (int i = 1; i <= 4; ++i) {
      for (int j = 0; j < 8; ++j) {
        nxt[j] = transfer(vec[j], i);
      }
      if (st.contains(hashv(nxt)))
        continue;
      st.emplace(hashv(nxt));
      Q.emplace(nxt, d + 1);
    }
  }
}
auto solve() {
  int a, b, c, d, m;
  int A, B, C, D, M;
  cin >> A >> B >> C >> D >> M;
  vector<int> status(8, 4);
  for (int i = 0; i < 32; ++i) {
    a = (A >> i) & 1;
    b = (B >> i) & 1;
    c = (C >> i) & 1;
    d = (D >> i) & 1;
    m = (M >> i) & 1;
    int msk = a * 4 + b * 2 + m;
    int ans = c * 2 + d;
    // cout << a << " " << b << " " << c << " " << d << " " << m << "\n";
    // cout << msk << " " << ans << "\n";
    if (status[msk] == 4 || status[msk] == ans) {
      status[msk] = ans;
    } else {
      cout << "-1\n";
      return;
    }
  }
  int ans = 0;
  dbg(status);
  for (int j = 0; j < 8; ++j) {
    int cur = status[j];
    ans += cur * pw5[j];
  }
  cout << dis[ans] << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  cin >> _;
  while (_--) {
    solve();
  }
}
