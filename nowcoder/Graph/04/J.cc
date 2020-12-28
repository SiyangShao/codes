#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class Cap> struct dinic {
  struct edge {
    int from, to;
    Cap w;
    edge(int _f, int _t, Cap _w) : from(_f), to(_t), w(_w){};
  };
  vector<vector<int>> E;
  vector<edge> edg;
  vector<int> d;
  int n;
  dinic(int _n) : n(_n), E(_n), d(_n) {}
  void addEdge(int u, int v, Cap w) {
    int id = edg.size();
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  auto dfs(int u, int t, Cap flow) {
    if (u == t)
      return flow;
    Cap sum = 0;
    for (auto id : E[u]) {
      if (edg[id].w != 0 && d[edg[id].to] == d[u] + 1) {
        auto tmp = dfs(edg[id].to, t, min(flow, edg[id].w));
        edg[id].w -= tmp, edg[id ^ 1].w += tmp, sum += tmp, flow -= tmp;
      }
    }
    if (sum == 0)
      d[u] = 0;
    return sum;
  }
  bool level(int s, int t) {
    fill(d.begin(), d.end(), 0);
    queue<int> Q;
    Q.emplace(s);
    d[s] = 1;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      if (u == t)
        return true;
      for (auto id : E[u]) {
        auto v = edg[id].to;
        if (d[v] == 0 && edg[id].w != 0)
          Q.emplace(v), d[v] = d[u] + 1;
      }
    }
    return false;
  }
  auto solve(int s, int t) {
    Cap ans = 0;
    while (level(s, t))
      ans += dfs(s, t, numeric_limits<Cap>::max());
    return ans;
  }
};
auto solve() {
  ll k, c, m;
  cin >> k >> c >> m;
  vector<vector<ll>> mp(k + c, vector<ll>(k + c));
  for (auto &i : mp) {
    for (auto &j : i) {
      cin >> j;
      if (j == 0) {
        j = 1e16;
      }
    }
  }
  for (ll t = 0; t < k + c; ++t) {
    for (ll i = 0; i < k + c; ++i) {
      for (ll j = 0; j < k + c; ++j) {
        mp[i][j] = min(mp[i][j], mp[i][t] + mp[t][j]);
      }
    }
  }
  function<bool(ll)> judge = [&](ll u) {
    dinic<ll> G(k + c + 2);
    for (ll i = 0; i < k; ++i) {
      G.addEdge(i, k + c, m);
    }
    for (ll i = k; i < k + c; ++i) {
      G.addEdge(k + c + 1, i, 1);
      for (ll j = 0; j < k; ++j) {
        if (mp[i][j] <= u) {
          G.addEdge(i, j, 1);
        }
      }
    }
    return G.solve(k + c + 1, k + c) == c;
  };
  ll L = 0, R = 200, ans = 200;
  while (L <= R) {
    ll mid = (L + R) / 2;
    if (judge(mid)) {
      R = mid - 1;
      ans = min(ans, mid);
    } else {
      L = mid + 1;
    }
  }
  cout << ans << "\n";
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