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
  ll r, c, d;
  cin >> r >> c >> d;
  vector<string> mp(r), in(r);
  for (auto &i : mp) {
    cin >> i;
  }
  for (auto &i : in) {
    cin >> i;
  }
  ll sum = 0;
  function<ll(ll, ll)> cal = [&](ll x, ll y) { return x * c + y; };
  dinic<ll> G(r * c * 2 + 2);
  ll S = r * c * 2, T = r * c * 2 + 1;
  for (ll i = 0; i < r; ++i) {
    for (ll j = 0; j < c; ++j) {
      ll pos = cal(i, j);
      G.addEdge(pos, pos + r * c, mp[i][j] - '0');
      if (in[i][j] == 'L') {
        G.addEdge(S, pos, 1);
        sum++;
      }
    }
  }
  function<bool(ll, ll)> judge = [&](ll x, ll y) {
    return (x < d || y < d || x + d >= r || y + d >= c);
  };
  for (ll i = 0; i < r; ++i) {
    for (ll j = 0; j < c; ++j) {
      ll pos = cal(i, j);
      if (judge(i, j)) {
        G.addEdge(pos + r * c, T, 1e16);
      }
      for (ll ii = 0; ii < r; ++ii) {
        for (ll jj = 0; jj < c; ++jj) {
          if (ii == i && jj == j)
            continue;
          if (abs(ii - i) + abs(jj - j) <= d) {
            ll pos2 = cal(ii, jj);
            G.addEdge(pos + r * c, pos2, 1e16);
          }
        }
      }
    }
  }
  cout << sum - G.solve(S, T) << "\n";
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