#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class Flow, class Cost> struct Primal_Dual {
  struct edge {
    int u, v;
    Flow f;
    Cost c;
    edge(int _u, int _v, Flow _f, Cost _c) : u(_u), v(_v), f(_f), c(_c) {};
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
    inf_flow = 1e16, inf_cost = 1e16;
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
          if (!vis[v])
            Q.emplace(dis[v], v);
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
          if (!vis[v])
            vis[v] = 1, Q.push(v);
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
      for (int i = 0; i < n; ++i)
        h[i] += dis[i];
      for (int i = t; i != s; i = p[i].first)
        minf = min(minf, edg[p[i].second].f);
      for (int i = t; i != s; i = p[i].first)
        edg[p[i].second].f -= minf, edg[p[i].second ^ 1].f += minf;
      maxf += minf, minc += minf * h[t];
    }
    return {maxf, minc};
  }
};
map<ll, ll> mp;
ll find(ll x) {
  if (mp.contains(x))
    return mp[x];
  ll ori = x;
  ll cnt = 0;
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      while (x % i == 0) {
        x /= i;
        cnt++;
      }
      if (mp.contains(x)) {
        mp[ori] = mp[x] + cnt;
        return mp[ori];
      }
    }
  }
  if (x != 1) {
    cnt++;
  }
  mp[ori] = cnt;
  return cnt;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  vector<vector<ll>> E(n);
  vector<ll> all;
  auto check = [&](ll id) {
    auto x = a[id];
    for (ll i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        E[id].emplace_back(i);
        all.emplace_back(i);
        if (i != x / i) {
          E[id].emplace_back(x / i);
          all.emplace_back(x / i);
        }
      }
    }
  };
  for (ll i = 0; i < n; ++i)
    check(i);
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  int s = n + (int)all.size(), t = s + 1;
  Primal_Dual<ll, ll> G(n + (int)all.size() + 2);
  for (int i = 0; i < n; ++i) {
    G.addEdge(s, i, 1, 0);
  }
  for (int i = n; i < n + (int)all.size(); i++) {
    G.addEdge(i, t, 1, 0);
  }
  for (int i = 0; i < n; ++i) {
    sort(E[i].begin(), E[i].end(), greater<>());
    for (auto j : E[i]) {
      auto can_div = a[i] / j;
      auto cost = find(can_div);
      auto it = lower_bound(all.begin(), all.end(), j);
      auto v = (int)(it - all.begin()) + n;
      G.addEdge(i, v, 1, -cost);
    }
  }
  auto [maxf, minc] = G.solve(s, t);
  cout << -minc << endl;
}
