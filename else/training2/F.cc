#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
array dx = {-1, -1, -1, 0, 0, 1, 1, 1};
array dy = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<vector<int>> result;
bool check(int n, int m, int k, auto &mp, bool get_result = false) {
  vector vis(n, vector<int>(m, 0));
  // bfs from '.'
  auto valid = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; };
  queue<tuple<int, int, int>> Q;
  for (int i = 0; i < m; i++) {
    Q.emplace(-1, i, 0);
    Q.emplace(n, i, 0);
  }
  for (int i = 0; i < n; ++i) {
    Q.emplace(i, -1, 0);
    Q.emplace(i, m, 0);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == '.') {
        Q.emplace(i, j, 0);
      }
    }
  }
  while (!Q.empty()) {
    auto [u, v, d] = Q.front();
    Q.pop();
    if (valid(u, v)) {
      if (vis[u][v])
        continue;
      vis[u][v] = 1;
    }
    if (d + 1 > k) {
      continue;
    }
    for (int i = 0; i < 8; ++i) {
      int x = u + dx[i];
      int y = v + dy[i];
      if (!valid(x, y))
        continue;
      Q.emplace(x, y, d + 1);
    }
  }
  if(get_result) result = vis;
  // traverse
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!vis[i][j]) {
        Q.emplace(i, j, 0);
      }
      vis[i][j] = 0;
    }
  }
  while (!Q.empty()) {
    auto [u, v, d] = Q.front();
    Q.pop();
    if (valid(u, v)) {
      if (vis[u][v])
        continue;
      vis[u][v] = 1;
    }
    if (d + 1 > k) {
      continue;
    }
    for (int i = 0; i < 8; ++i) {
      int x = u + dx[i];
      int y = v + dy[i];
      if (!valid(x, y))
        continue;
      Q.emplace(x, y, d + 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int here = mp[i][j] == '.' ? 0 : 1;
      if (here != vis[i][j])
        return false;
    }
  }
  return true;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<string> mp(n);
  for (auto &i : mp) {
    cin >> i;
  }
  int l = 0, r = min(n, m);
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(n, m, mid, mp)) {
      l = mid + 1;
      ans = max(ans, mid);
    } else {
      r = mid - 1;
    }
  }
  check(n, m, ans, mp, true);
  cout<<ans<<"\n";
  for(int i = 0 ; i <n; ++i){
    for(int j = 0 ;j < m;++j){
      if(!result[i][j]){
        cout<<"X";
      }else{
        cout<<".";
      }
    }
    cout << "\n";
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