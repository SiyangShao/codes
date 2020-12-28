#include <bits/stdc++.h>
using namespace std;
template <class Flow> struct dinic {
  struct edge {
    int u, v;
    Flow f;
    edge(int _u, int _v, Flow _f) : u(_u), v(_v), f(_f){};
  };
  vector<vector<int>> E;
  vector<edge> edg;
  vector<int> d, cur;
  int n;
  dinic(int _n) : E(_n), d(_n), cur(_n), n(_n) {}
  void addEdge(int u, int v, Flow w) {
    int id = (int)edg.size();
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, w);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  auto dfs(int u, int t, Flow flow) {
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
  bool level(int s, int t) {
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
  auto solve(int s, int t) {
    Flow ans = 0;
    while (level(s, t))
      ans += dfs(s, t, 1e16);
    return ans;
  }
};
using ld = long double;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  ld V, a;
  cin >> V >> a;
  dinic<ll> G(n + 1), F(n), W(n), E(n + 1);
  int S = n;
  vector<tuple<int, int, ll>> edg(m);
  // map<pair<int,int>, ld> capacity;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    ll c;
    cin >> c;
    // capacity[{u,v}] = capacity[{v,u}] = c;
    c = c * ll(1e9);
    // cout << c << "\n";
    edg[i] = {u, v, c};
    G.addEdge(u, v, c);
    F.addEdge(u, v, c);
    W.addEdge(u, v, c);
    E.addEdge(u, v, c);
  }
  ll F_max = F.solve(0, 2);
  ll W_max = W.solve(1, 2);
  G.addEdge(S, 0, 1e16);
  G.addEdge(S, 1, 1e16);
  ll Z_max = G.solve(S, 2);
  // cout << fixed << setprecision(10) << F_max << " " << W_max << " " << Z_max
  //      << "\n";
  // cout << F_max << " " << W_max << " " << Z_max << "\n";
  function<ld(ld)> cal = [&](ll f_f) {
    ld f = ld(f_f) / 1e9;
    ld real_z = ld(Z_max) / 1e9;
    return pow(f, a) * pow(real_z - f, 1 - a);
  };
  ll L = ll((ld)(Z_max)*a);
  L = max(L, Z_max - W_max);
  L = min(F_max, L);
  // ll L = Z_max - W_max, R = F_max;
  // for (int _ = 1; _ <= 200; ++_) {
  //   ll _len = R - L;
  //   ll mid1 = L + _len / 3;
  //   ll mid2 = R - _len / 3;
  //   if (cal(mid1) > cal(mid2)) {
  //     R = mid2;
  //   } else {
  //     L = mid1;
  //   }
  // }
  // cout << fixed << setprecision(10) << L << " " << R << "\n";
  auto ans = cal(L);
  ll real_F = L;
  ll real_W = Z_max - real_F;
  ans = ans / pow(V, a);
  E.addEdge(S, 0, real_F);
  // E.addEdge(S, 1, real_W);
  E.solve(S, 2);
  map<pair<int, int>, ll> mpF, mpW;
  for (int i = 0; i < (int)E.edg.size(); i += 2) {
    // cout << i << " " << E.edg.size() << endl;
    auto [u, v, f] = E.edg[i];
    cout << G.edg[i].f << " " << f << " \n";
    // cout << u << ", " << v << endl;
    if (u == S || v == S)
      continue;
    if (abs(f - get<2>(edg[i / 2])) == 0)
      continue;
    ll new_w = min(E.edg[i].f, E.edg[i + 1].f);
    mpF[{u, v}] = get<2>(edg[i / 2]) - f;
    mpF[{v, u}] = f - get<2>(edg[i / 2]);
    edg[i / 2] = {u, v, new_w};
    E.edg[i].f = E.edg[i + 1].f = new_w;
  }
  E.addEdge(S, 1, real_W);
  E.solve(S, 2);
  for (int i = 0; i < (int)E.edg.size(); i += 2) {
    // cout << i << " " << E.edg.size() << endl;
    auto [u, v, f] = E.edg[i];
    // cout << u << ", " << v << endl;
    if (u == S || v == S)
      continue;
    if (abs(f - get<2>(edg[i / 2])) == 0)
      continue;
    // ll new_w = min(E.edg[i].f, E.edg[i + 1].f);
    mpW[{u, v}] = get<2>(edg[i / 2]) - f;
    mpW[{v, u}] = f - get<2>(edg[i / 2]);
    // edg[i / 2] = {u, v, new_w};
    // E.edg[i].f = E.edg[i + 1].f = new_w;
  }

  constexpr long double eps = 1e-9;
  for (auto [u, v, xxx] : edg) {
    auto _f = mpF[{u, v}];
    auto _w = mpW[{u, v}];
    ld f = ld(_f) / ld(1e9);
    ld w = ld(_w) / ld(1e9);
    f /= V;
    if (abs(f) < eps)
      f = 0;
    cout << fixed << setprecision(12) << f << " " << w << "\n";
  }
  cout << fixed << setprecision(12) << ans << "\n";
}