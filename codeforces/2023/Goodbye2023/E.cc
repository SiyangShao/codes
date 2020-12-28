#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
int n;
vector<int> p, a, siz, hson, cnt, L, R, dfn;
int totCol, totNode;
ll ans;
vector<vector<int>> E;
void add(int u) {
  if (cnt[a[u]] == 0)
    totCol++;
  cnt[a[u]]++;
}
void del(int u) {
  cnt[a[u]]--;
  if (cnt[a[u]] == 0)
    totCol--;
}
void addRange(int u) {
  for (int i = L[u]; i < R[u]; ++i) {
    add(dfn[i]);
  }
}
void delRange(int u) {
  for (int i = L[u]; i < R[u]; ++i) {
    del(dfn[i]);
  }
}
void init(int u) {
  dfn[totNode] = u;
  L[u] = totNode;
  totNode++;
  for (auto v : E[u]) {
    init(v);
    siz[u] += siz[v];
    if (hson[u] == -1 || siz[hson[u]] < siz[v]) {
      hson[u] = v;
    }
  }
  R[u] = totNode;
}
ll dfs(int u, bool keep = false) {
  ll mx = 1, mi = 1;
  auto upd = [&](ll tmp) {
    if (tmp >= mx) {
      mi = mx;
      mx = tmp;
    } else if (tmp > mi) {
      mi = tmp;
    }
  };
  for (auto v : E[u]) {
    if (v == hson[u])
      continue;
    ll tmp = dfs(v);
    upd(tmp);
  }
  if (hson[u] != -1) {
    ll tmp = dfs(hson[u], true);
    upd(tmp);
  }
  for (auto v : E[u]) {
    if (v == hson[u])
      continue;
    addRange(v);
  }
  add(u);
  ans = max(ans, mx * mi);
  dbg(cnt);
  cout << u + 1 << " " << mx << " " << mi << " " << totCol << "\n";
  ll returnVal = totCol;
  if (p[u] != -1) {
    add(p[u]);
    returnVal = totCol;
    del(p[u]);
  }
  if (!keep) {
    delRange(u);
  }
  return returnVal;
}
auto solve() {
  cin >> n;
  p.assign(n, 0);
  a.resize(n);
  E.assign(n, vector<int>{});
  siz.assign(n, 1);
  hson.assign(n, -1);
  cnt.assign(n, 0);
  L.resize(n), R.resize(n), dfn.resize(n);
  totCol = totNode = 0;
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
    p[i]--;
    E[p[i]].emplace_back(i);
  }
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  ans = 0;
  init(0);
  dfs(0);
  cout << ans << "\n";
  delRange(0);
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