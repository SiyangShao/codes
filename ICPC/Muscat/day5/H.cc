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
  int n;
  vector<int> fa, siz;
  DSU(int _) : n(_), fa(_), siz(_) {
    iota(fa.begin(), fa.end(), 0);
    fill(siz.begin(), siz.end(), 1);
  };
  int find(int u) {
    if (u != fa[u]) {
      fa[u] = find(fa[u]);
    }
    return fa[u];
  }
  bool same(int u, int v) {
    u = find(u), v = find(v);
    return u == v;
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return;
    fa[u] = v;
    siz[v] += siz[u];
  }
};
auto solve() {
  int n;
  cin >> n;
  n *= 2;
  vector<pair<ll, ll>> node(n);
  map<ll, vector<int>> mpx, mpy;
  for (auto &[x, y] : node) {
    cin >> x >> y;
  }
  for (int i = 0; i < n; ++i) {
    mpx[node[i].first].emplace_back(i);
    mpy[node[i].second].emplace_back(i);
  }
  int m = (int)mpx.size();
  vector<vector<int>> has_node(m);
  map<ll, int> rev;
  {
    int cnt = 0;
    for (auto &&[x, _] : mpx) {
      rev[x] = cnt++;
      for (auto i : _) {
        has_node[rev[x]].emplace_back(i);
      }
    }
  }
  dbg(m, has_node);
  vector<int> in_x(n);
  for (int i = 0; i < n; ++i) {
    in_x[i] = rev[node[i].first];
  }
  dbg(in_x);
  DSU dsu(m);
  vector<vector<tuple<int, int, int>>> E(m);
  vector<int> vis(m, 0);
  for (auto &[x, y] : mpy) {
    for (int i = 1; i < (int)y.size(); ++i) {
      int u = y[i - 1], v = y[i];
      int uu = in_x[u], vv = in_x[v];
      if (dsu.same(uu, vv))
        continue;
      dsu.merge(uu, vv);
      E[uu].emplace_back(vv, u, v);
      E[vv].emplace_back(uu, v, u);
    }
  }
  dbg(E);
  vector<pair<int, int>> ans;
  vector<int> match(n, 0);
  function<int(int, int)> dfs = [&](int u, int from) {
    vis[u] = 1;
    vector<pair<int, int>> same;
    for (auto [v, cur, nxt] : E[u]) {
      if (vis[v])
        continue;
      int real_nxt = dfs(v, nxt);
      if (real_nxt != -1) {
        same.emplace_back(cur, real_nxt);
      }
    }
    sort(same.begin(), same.end());
    dbg(same);
    vector<pair<int, int>> special;
    for (int i = 0; i < (int)same.size(); ++i) {
      if (i + 1 < (int)same.size() && same[i].first == same[i + 1].first) {
        ans.emplace_back(same[i].second, same[i + 1].second);
        i++;
      } else {
        if (same[i].first == from) {
          special.emplace_back(from, same[i].second);
        } else {
          ans.emplace_back(same[i].first, same[i].second);
        }
        match[same[i].first] = 1;
      }
    }
    assert(special.size() <= 1);
    vector<int> other;
    for (auto i : has_node[u]) {
      if (i == from || match[i])
        continue;
      other.emplace_back(i);
    }
    dbg(u, from, other, special, has_node);
    if (other.size() % 2 == 0) {
      for (int i = 0; i < other.size(); i += 2) {
        ans.emplace_back(other[i], other[i + 1]);
      }
      if (!special.empty()) {
        ans.emplace_back(special[0].first, special[0].second);
        return -1;
      } else {
        return from;
      }
    } else {
      for (int i = 1; i < other.size(); i += 2) {
        ans.emplace_back(other[i], other[i + 1]);
      }
      if (!special.empty()) {
        assert(from != -1);
        ans.emplace_back(from, other[0]);
        return special[0].second;
      } else {
        ans.emplace_back(from, other[0]);
        return -1;
      }
    }
  };
  for (int i = 0; i < m; ++i) {
    if (vis[i])
      continue;
    dfs(i, -1);
  }
  dbg(ans);
  vector<int> cannot;
  vector<pair<int, int>> real_ans;
  for (auto &[u, v] : ans) {
    if (u != -1) {
      real_ans.emplace_back(u, v);
    } else {
      cannot.emplace_back(v);
    }
  }
  cout << real_ans.size() << "\n";
  for (auto &[u, v] : real_ans) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
  for (int i = 0; i < cannot.size(); i += 2) {
    cout << cannot[i] + 1 << " " << cannot[i + 1] + 1 << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}