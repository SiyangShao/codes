#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
struct DSU {
  vector<int> fa;
  DSU(int n) : fa(n) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  int same(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return true;
    return false;
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
auto solve() {
  int m, k;
  cin >> m >> k;
  set<pair<int, int>> st;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v)
      swap(u, v);
    st.emplace(u, v);
  }
  vector<vector<int>> E(k);
  vector<int> special(k), specialcnt(k), appear(k);
  bool flag = false;
  DSU dsu(k);
  dbg(st);
  for (auto [u, v] : st) {
    appear[u] = appear[v] = 1;
    if (u == v) {
      special[u] = 1;
      continue;
    }
    if (dsu.same(u, v))
      flag = true;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
    dsu.merge(u, v);
  }
  dbg(flag);
  if (flag) {
    int rt = 0;
    for (int i = 0; i < k; ++i) {
      if (appear[i]) {
        rt = i;
        break;
      }
    }
    for (int i = 0; i < k; ++i) {
      if (!appear[i])
        continue;
      if (!dsu.same(rt, i)) {
        cout << "impossible\n";
        return;
      }
    }
    vector<int> vis(k), inCircle(k), pa(k, -1);
    bool done = false;
    function<void(int, int)> dfs = [&](int u, int fa) {
      vis[u] = 1;
      pa[u] = fa;
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        if (vis[v]) {
          while (u != v) {
            inCircle[u] = 1;
            u = pa[u];
          }
          inCircle[v] = 1;
          done = true;
          return;
        }
        dfs(v, u);
        if (done)
          return;
      }
    };
    dfs(rt, -1);
    dbg(inCircle);
    for (int i = 0; i < k; ++i) {
      if (!appear[i])
        continue;
      if (inCircle[i]) {
        int cnt = 0;
        for (auto j : E[i]) {
          if (inCircle[j])
            cnt++;
        }
        if (cnt > 2) {
          cout << "impossible\n";
          return;
        }
      } else {
        if (E[i].size() != 1 || !inCircle[E[i][0]]) {
          cout << "impossible\n";
          return;
        }
        if (special[i]) {
          cout << "impossible\n";
          return;
        }
      }
    }
    cout << "possible\n";
  } else {
    vector<int> vis(k), dis(k), pa(k), onChain(k);
    function<bool(int)> check = [&](int rt) {
      int maxDep = rt;
      function<void(int, int)> dfs = [&](int u, int fa) {
        vis[u] = 1;
        pa[u] = fa;
        if (dis[u] > dis[maxDep])
          maxDep = u;
        for (auto v : E[u]) {
          if (v == fa)
            continue;
          dis[v] = dis[u] + 1;
          dfs(v, u);
        }
      };
      dis[rt] = 0;
      dfs(rt, rt);
      pa[rt] = -1;
      if (maxDep == rt) {
        return true;
      }
      rt = maxDep;
      dis[rt] = 0;
      dfs(rt, rt);
      pa[rt] = -1;
      {
        int u = maxDep;
        while (u != rt) {
          onChain[u] = 1;
          u = pa[u];
        }
        onChain[rt] = 1;
      }
      if (special[rt]) {
        specialcnt[E[rt][0]]++;
      }
      if (special[maxDep]) {
        specialcnt[E[maxDep][0]]++;
      }
      int specialCan1 = E[rt][0], specialCan2 = E[maxDep][0];
      if (specialCan1 == specialCan2) {
        int cnt = 0;
        for (auto v : E[specialCan1]) {
          if (special[v])
            cnt++;
        }
        return cnt <= 2;
      }
      function<bool(int, int)> cc = [&](int u, int fa) {
        if (!onChain[u]) {
          dbg(u);
          if (E[u].size() > 1 || !onChain[E[u][0]])
            return false;
          if (special[u] && (E[u][0] != specialCan1 && E[u][0] != specialCan2))
            return false;
          if (special[u])
            specialcnt[E[u][0]]++;
        }
        bool flg = true;
        for (auto v : E[u]) {
          if (v == fa)
            continue;
          flg = flg && cc(v, u);
        }
        return flg;
      };
      bool flg = cc(rt, rt);
      dbg(rt, maxDep);
      dbg(flg, specialcnt[specialCan1], specialcnt[specialCan2], onChain);
      if (specialcnt[specialCan1] > 1 || specialcnt[specialCan2] > 1)
        flg = false;
      return flg;
    };
    for (int i = 0; i < k; ++i) {
      if (vis[i])
        continue;
      if (!check(i)) {
        cout << "impossible\n";
        return;
      }
    }
    cout << "possible\n";
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