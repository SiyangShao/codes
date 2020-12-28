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
        if (sum == flow)
          return sum;
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
constexpr ll inf = 1e16;
dinic<ll> G(1600 + 2);
vector<ll> val(1600), col(1600);
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> mp(n, vector<ll>(m, 0));
  for (auto &i : mp) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  ll sum1 = 0, sum2 = 0, mx = 0, cnt1 = 0, cnt2 = 0;
  function<ll(ll, ll)> cal = [&](ll x, ll y) { return x * m + y; };
  array dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
  G.edg.clear();
  for (auto &i : G.E) {
    i.clear();
  }
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      val[cal(i, j)] = mp[i][j];
      if ((i + j) % 2 == 0) {
        col[cal(i, j)] = 0;
        G.addEdge(n * m, cal(i, j), 0);
        for (ll k = 0; k < 4; ++k) {
          ll x = i + dx[k], y = j + dy[k];
          if (x >= 0 && y >= 0 && x < n && y < m) {
            G.addEdge(cal(i, j), cal(x, y), inf);
          }
        }
      } else {
        col[cal(i, j)] = 1;
        G.addEdge(cal(i, j), n * m + 1, 0);
      }
    }
  }
  function<bool(ll)> check = [&](ll mid) {
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
      for (ll j = 0; j < m; ++j) {
        if ((i + j) % 2 == 0) {
          ans += mid - mp[i][j];
        }
      }
    }
    for (auto &[u, v, w] : G.edg) {
      if (u == n * m) {
        w = mid - val[v];
      } else if (v == n * m) {
        w = 0;
      } else if (u == n * m + 1) {
        w = 0;
      } else if (v == n * m + 1) {
        w = mid - val[u];
      } else {
        assert(col[u] + col[v] == 1);
        if (col[u] == 0) {
          w = inf;
        } else {
          w = 0;
        }
      }
    }
    return G.solve(n * m, n * m + 1) == mid * cnt1 - sum1;
  };
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      mx = max(mx, mp[i][j]);
      if ((i + j) % 2 == 0) {
        cnt1++;
        sum1 += mp[i][j];
      } else {
        cnt2++;
        sum2 += mp[i][j];
      }
    }
  }
  if ((n * m) % 2 == 1) {
    ll ans = (sum1 - sum2) / (cnt1 - cnt2);
    if (ans < mx) {
      cout << "-1\n";
      return;
    }
    if (check(ans)) {
      cout << ans * cnt1 - sum1 << "\n";
    } else {
      cout << "-1\n";
    }
  } else {
    ll l = mx, r = 2e9, ans = -1;
    while (l <= r) {
      ll mid = (l + r) / 2;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans * cnt1 - sum1 << "\n";
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