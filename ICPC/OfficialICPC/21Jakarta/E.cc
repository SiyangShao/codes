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
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  vector<int> dis(n * 2);
  for (int i = 1; i < n * 2; ++i) {
    dis[i] = dis[i - 1] + 1;
  }
  for(int i = 0 ;i < m; ++i){
    
  }
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