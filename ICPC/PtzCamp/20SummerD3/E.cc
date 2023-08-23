#include <bits/stdc++.h>
using namespace std;
template <class Flow, class Cost> struct Primal_Dual { // based on EK
  struct edge {
    int u, v;
    Flow f;
    Cost c;
    edge(int _u, int _v, Flow _f, Cost _c) : u(_u), v(_v), f(_f), c(_c){};
  };
  int n;
  Cost inf_cost;
  Flow inf_flow;
  vector<vector<int>> E;
  vector<edge> edg;
  vector<pair<int, int>> p;
  vector<Cost> dis, h;
  vector<int> vis;
  Primal_Dual(int _n) : n(_n), E(_n), p(_n), dis(_n), h(_n), vis(_n) {
    inf_flow = numeric_limits<Flow>::max();
    inf_cost = numeric_limits<Cost>::max();
  };
  void addEdge(int u, int v, Flow f, Cost c) {
    int id = (int)edg.size();
    edg.emplace_back(u, v, f, c);
    edg.emplace_back(v, u, 0, -c);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  bool dijkstra(int s, int t) {
    using pii = pair<Cost, int>;
    priority_queue<pii, vector<pii>, greater<>> Q;
    fill(dis.begin(), dis.end(), inf_cost);
    fill(vis.begin(), vis.end(), 0);
    dis[s] = 0;
    Q.emplace(dis[s], s);
    while (!Q.empty()) {
      int u = Q.top().second;
      Q.pop();
      if (vis[u])
        continue;
      vis[u] = 1;
      for (auto id : E[u]) {
        auto [_, v, f, c] = edg[id];
        c = c + h[u] - h[v];
        if (f > 0 && dis[v] > dis[u] + c) {
          dis[v] = dis[u] + c;
          p[v].first = u;
          p[v].second = id;
          if (!vis[v]) {
            Q.emplace(dis[v], v);
          }
        }
      }
    }
    return dis[t] != inf_cost;
  }
  void spfa(int s) {
    queue<int> Q;
    fill(h.begin(), h.end(), inf_cost);
    h[s] = 0, vis[s] = 1;
    Q.emplace(s);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      vis[u] = 0;
      for (auto id : E[u]) {
        auto [_, v, f, c] = edg[id];
        if (f > 0 && h[v] > h[u] + c) {
          h[v] = h[u] + c;
          if (!vis[v]) {
            vis[v] = 1;
            Q.push(v);
          }
        }
      }
    }
  }
  pair<Flow, Cost> solve(int s, int t) {
    spfa(s);
    Flow maxf = 0;
    Cost minc = 0;
    while (dijkstra(s, t)) {
      auto minf = inf_flow;
      for (int i = 0; i < n; ++i) {
        h[i] += dis[i];
      }
      for (int i = t; i != s; i = p[i].first) {
        minf = min(minf, edg[p[i].second].f);
      }
      for (int i = t; i != s; i = p[i].first) {
        edg[p[i].second].f -= minf;
        edg[p[i].second ^ 1].f += minf;
      }
      maxf += minf;
      minc += minf * h[t];
    }
    return {maxf, minc};
  }
};
using ll = long long;
auto solve() {
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> id;
  vector<vector<ll>> neigh(n);
  vector<tuple<ll, ll, ll>> vec(n);
  int tmp = 0;
  for (auto &[a, b, c] : vec) {
    cin >> a >> b >> c;
    ll mid = (-b) / (2 * a);
    vector<ll> test;
    for (int i = 1; i <= n; ++i) {
      test.emplace_back(i);
      test.emplace_back(m - i + 1);
    }
    for (ll i = max(1LL, mid); i <= min(m, mid + n - 1); ++i) {
      test.emplace_back(i);
    }
    for (ll i = max(1LL, mid - n + 1); i <= min(m, mid); ++i) {
      test.emplace_back(i);
    }
    ranges::sort(test);
    test.erase(unique(test.begin(), test.end()), test.end());
    sort(test.begin(), test.end(),
         [&](ll x, ll y) { return a * x * x + b * x < a * y * y + b * y; });
    for (ll i = 0; i < n; ++i) {
      neigh[tmp].emplace_back(test[i]);
      id.emplace_back(test[i]);
    }
    tmp++;
  }
  sort(id.begin(), id.end());
  id.erase(unique(id.begin(), id.end()), id.end());
  auto getid = [&](ll x) {
    return (int)(lower_bound(id.begin(), id.end(), x) - id.begin());
  };
  Primal_Dual<ll, ll> G(n + (int)id.size() + 3);
  int S = n + (int)id.size(), T = n + (int)id.size() + 1;
  int mid = T + 1;
  for (int i = 0; i < n; ++i) {
    G.addEdge(S, i, 1, 0);
  }
  for (int j = 0; j < (int)id.size(); ++j) {
    G.addEdge(j + n, T, 1, 0);
  }
  for (int i = 0; i < n; ++i) {
    auto [a, b, c] = vec[i];
    for (auto j : neigh[i]) {
      G.addEdge(i, getid(j) + n, 1, a * j * j + b * j + c);
    }
  }
  ll pre = 0;
  for (int i = 0; i < n; ++i) {
    G.addEdge(mid, S, 1, 0);
    auto [x, y] = G.solve(mid, T);
    pre += y;
    cout << pre;
    if (i + 1 != n) {
      cout << " ";
    }
  }
  cout << "\n";
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