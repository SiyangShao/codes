#include <bits/stdc++.h>
using namespace std;
template <class Cap> struct dinic {
  struct edge {
    int from, to;
    Cap w;
    edge(int _f, int _t, Cap _w) : from(_f), to(_t), w(_w){};
  };
  vector<vector<int>> E;
  vector<edge> edg;
  vector<int> d, q;
  int n;
  dinic(int _n) : n(_n), E(_n), d(_n), q(_n) {}
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
    int l = 0, r = 0;
    d[s] = 1, q[r++] = s;
    while (l < r) {
      int u = q[l++];
      if (u == t)
        return true;
      for (auto id : E[u]) {
        auto v = edg[id].to;
        if (d[v] == 0 && edg[id].w != 0)
          q[r++] = v, d[v] = d[u] + 1;
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
using ll = long long;
auto solve() {
  ll n1, n2, m, q;
  cin >> n1 >> n2 >> m >> q;
  dinic<ll> E(n1 + n2 + 2);
  for (ll i = 1; i <= n1; ++i) {
    E.addEdge(0, i, 1);
  }
  for (ll i = 1; i <= n2; ++i) {
    E.addEdge(i + n1, n1 + n2 + 1, 1);
  }
  ll beg = E.edg.size();
  for (ll i = 0; i < m; ++i) {
    ll u, v;
    cin >> u >> v;
    v += n1;
    E.addEdge(u, v, 1);
  }
  ll sz = E.edg.size();
  ll all = E.solve(0, n1 + n2 + 1);
  auto &G = E.E;
  auto &edg = E.edg;
  ll sum = 0;
  for (ll i = beg; i < sz; i += 2) {
    if (edg[i].w == 0) {
      sum += (i - beg) / 2 + 1;
      // cout<<(i-beg)/2+1<<" ";
    }
  }
  // cout<<"\n";
  vector<ll> cut;
  for (ll i = 1; i <= n1; ++i) {
    if (E.d[i] == 0) {
      cut.emplace_back(i);
      // cout<<i<<" ";
    }
  }
  cout << "\n";
  for (ll i = n1 + 1; i <= n1 + n2; ++i) {
    if (E.d[i] != 0) {
      cut.emplace_back(i);
      // cout<<i-n1<<" ";
    }
  }
  assert(cut.size() == all);
  ll cur = 0;
  auto update = [&]() {
    auto u = cut[cur];
    cur++;
    if (u <= n1) {
      cout << u << "\n";
      for (auto id : G[u]) {
        auto [from, to, w] = edg[id];
        if (from == 0 || to == n1 + n2 + 1)
          continue;
        if (w == 0) {
          edg[id].w = 1;
          // cout<<(id - beg)/2+1<<"\n";
          sum -= (id - beg) / 2 + 1;
          cout << sum << "\n";
          break;
        }
      }
    } else {
      cout << -(u - n1) << "\n";
      for (auto id : G[u]) {
        auto [from, to, w] = edg[id ^ 1];
        if (from == 0 || to == n1 + n2 + 1)
          continue;
        if (w == 0) {
          edg[id ^ 1].w = 1;
          // cout<<((id^1) - beg)/2+1<<"\n";
          sum -= ((id ^ 1) - beg) / 2 + 1;
          cout << sum << "\n";
          break;
        }
      }
    }
  };
  while (q--) {
    ll op;
    cin >> op;
    if (op == 1) {
      all--;
      cout << "1\n";
      update();
    } else {
      cout << all << "\n";
      for (ll i = beg; i < sz; i += 2) {
        if (edg[i].w == 0) {
          cout << (i - beg) / 2 + 1 << " ";
        }
      }
      cout << "\n";
    }
    // cout << "===\n";
    cout.flush();
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