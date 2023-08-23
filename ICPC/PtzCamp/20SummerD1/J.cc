#include <bits/stdc++.h>
using namespace std;
template <class Flow> struct dinic {
  struct edge {
    long long u, v;
    Flow f;
    edge(int _u, int _v, Flow _f) : u(_u), v(_v), f(_f){};
  };
  vector<vector<long long>> E;
  vector<edge> edg;
  vector<long long> d, cur;
  long long n;
  dinic(long long _n) : E(_n), d(_n), cur(_n), n(_n) {}
  void addEdge(long long u, long long v, Flow w) {
    int id = (int)edg.size();
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  auto dfs(long long u, long long t, Flow flow) {
    if (u == t)
      return flow;
    Flow sum = 0;
    while (cur[u] < (int)E[u].size()) {
      auto id = E[u][cur[u]];
      auto [_, v, f] = edg[id];
      auto c = min(flow, f);
      if (d[u] + 1 == d[v] && c > 0) {
        auto add = dfs(v, t, c);
        sum += add, flow -= add, edg[id].f -= add, edg[id ^ 1].f += add;
      }
      if (!flow)
        break;
      cur[u]++;
    }
    if (!sum)
      d[u] = -1;
    return sum;
  }
  bool level(long long s, long long t) {
    fill(d.begin(), d.end(), -1), fill(cur.begin(), cur.end(), 0);
    queue<int> Q;
    Q.emplace(s), d[s] = 0;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (auto id : E[u]) {
        auto v = edg[id].v;
        if (d[v] == -1 && edg[id].f != 0)
          Q.emplace(v), d[v] = d[u] + 1;
      }
    }
    return d[t] != -1;
  }
  auto solve(long long s, long long t) {
    Flow ans = 0;
    while (level(s, t))
      ans += dfs(s, t, 1e18);
    return ans;
  }
};
using ll = long long;
constexpr ll X = 10010, Y = 8, Z = 8;
array<array<array<ll, Z>, Y>, X> a, b;
array<array<ll, Z>, Y> pre;
auto solve() {
  ll A, B, C;
  cin >> A >> B >> C;

  for (ll i = 0; i < A; ++i) {
    for (ll j = 0; j < B; ++j) {
      for (ll k = 0; k < C; ++k) {
        cin >> a[i][j][k];
      }
    }
  }
  for (ll i = 0; i < A; ++i) {
    for (ll j = 0; j < B; ++j) {
      for (ll k = 0; k < C; ++k) {
        cin >> b[i][j][k];
        pre[j][k] = 0;
      }
    }
  }
  constexpr ll inf = 1e18;
  for (ll i = 0; i < A; ++i) {
    dinic<ll> G(B * C + 2);
    ll S = B * C, T = B * C + 1;
    ll sum = 0;
    for (ll j = 0; j < B; ++j) {
      for (ll k = 0; k < C; ++k) {
        G.addEdge(S, j * C + k, a[i][j][k] + pre[j][k]);
        pre[j][k] += a[i][j][k];
        if (j + 1 < B) {
          G.addEdge(j * C + k, (j + 1) * C + k, inf);
        }
        if (k + 1 < C) {
          G.addEdge(j * C + k, j * C + k + 1, inf);
        }
        G.addEdge(j * C + k, T, b[i][j][k]);
        sum += b[i][j][k];
        pre[j][k] = max(0LL, pre[j][k] - b[i][j][k]);
        cout<<pre[j][k]<<" ";
      }
      cout<<"\n";
    }
    cout<<"\n";
    ll ans = G.solve(S, T);
    if (ans != sum) {
      cout << "NIE\n";
      return;
    }
  }
  for (ll i = 0; i < B; ++i) {
    for (ll j = 0; j < C; ++j) {
      // cout<<pre[i][j]<<" ";
      if (pre[i][j] != 0) {
        
        cout << "NIE\n";
        return;
      }
    }
    // cout << "\n";
  }
  cout << "TAK\n";
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