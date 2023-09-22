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
  cout << "+ " << n + 1 << endl;
  int tmp;
  cin >> tmp;
  assert(tmp == 1);
  cout << "+ " << n << endl;
  cin >> tmp;
  assert(tmp == 1);
  int l = 1, r = n;
  vector<int> p;
  while (l <= r) {
    p.emplace_back(r);
    if (l != r)
      p.emplace_back(l);
    r--;
    l++;
  }
  vector<int> mp(n + 1);
  for (int i = 0; i < n; ++i) {
    mp[p[i]] = i + 1;
  }
  // for (auto i : p) {
  //   cout << i << " ";
  // }
  // cout << "\n";
  vector<int> dis(n);
  for (int i = 2; i <= n; ++i) {
    cout << "? " << 1 << " " << i << endl;
    cin >> dis[i - 1];
  }
  int u = 1, d = 0;
  for (int i = 1; i <= n; ++i) {
    if (dis[i - 1] > d) {
      d = dis[i - 1];
      u = i;
    }
  }
  dis[u - 1] = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == u)
      continue;
    cout << "? " << i << " " << u << endl;
    cin >> dis[i - 1];
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  ranges::sort(id, [&](int x, int y) { return dis[x] < dis[y]; });
  for (auto &i : id) {
    i++;
    // cout << i << " ";
  }
  // cout << "\n";
  cout << "! ";
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    ans[id[i - 1]] = p[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  for (int i = 1; i <= n; ++i) {
    ans[id[i - 1]] = p[n - i];
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  int x;
  cin >> x;
  assert(x == 1);
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