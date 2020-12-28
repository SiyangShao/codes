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
  void addEdge(int u, int v, Flow w, bool single_side = false) {
    int id = (int)edg.size();
    if (single_side)
      edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    else
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
      ans += dfs(s, t, numeric_limits<Flow>::max());
    return ans;
  }
};
using ll = long long;
using ld = long double;
constexpr ld rev_mul = 1e9;
constexpr ll mul = 1e9;
constexpr ll inf = 1e16;
pair<ll, ll> get_F_W(int n, vector<tuple<int, int, ll>> &edg, ld a) {
  dinic<ll> G(n + 1), F(n), W(n);
  for (auto [u, v, w] : edg) {
    G.addEdge(u, v, w);
    F.addEdge(u, v, w);
    W.addEdge(u, v, w);
  }
  int S = n;
  G.addEdge(S, 0, inf, true);
  G.addEdge(S, 1, inf, true);
  auto f = F.solve(0, 2);
  auto w = W.solve(1, 2);
  auto g = G.solve(S, 2);
  ll X = static_cast<ll>(a * g);
  X = min(X, f);
  X = max(X, g - w);
  return {X, g - X};
};
void output_method(int n, ll F, ll W, vector<tuple<int, int, ll>> &edg,
                   ld val) {
  dinic<ll> G(n + 1);
  for (auto [u, v, w] : edg) {
    G.addEdge(u, v, w);
  }
  int S = n;
  G.addEdge(S, 0, F, true);
  G.addEdge(S, 1, W, true);
  G.solve(S, 2);
  dinic<ll> E(n + 1);
  for (int i = 0; i < (int)G.edg.size(); i += 2) {
    auto [u, v, w] = G.edg[i];
    if (u == S)
      break;
    ll real_flow = get<2>(edg[i / 2]) - w;
    if (real_flow == 0)
      continue;
    if (real_flow > 0) {
      E.addEdge(u, v, real_flow, true);
    } else {
      E.addEdge(v, u, -real_flow, true);
    }
  }
  E.addEdge(S, 0, F, true);
  E.solve(S, 2);
  map<pair<int, int>, pair<ll, ll>> ans;
  for (int i = 0; i < (int)E.edg.size(); i += 2) {
    auto [u, v, res] = E.edg[i];
    auto [_u, _v, w] = E.edg[i + 1];
    ans[{u, v}] = {w, res};
    ans[{v, u}] = {-w, -res};
  }
  for (auto [u, v, _] : edg) {
    auto [_f, _w] = ans[{u, v}];
    ld f = ld(_f) / rev_mul;
    ld w = ld(_w) / rev_mul;
    f = f / val;
    cout << fixed << setprecision(9) << f << " " << w << "\n";
  }
}
void output_ans(ll F, ll W, ld val, ld a) {
  ld f = ld(F) / rev_mul;
  f = f / val;
  ld w = ld(W) / rev_mul;
  cout << fixed << setprecision(9) << pow(f, a) * pow(w, 1 - a) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  ld val, a;
  cin >> val >> a;
  vector<tuple<int, int, ll>> edg(m);
  for (auto &[u, v, w] : edg) {
    cin >> u >> v >> w;
    u--, v--;
    w *= mul;
  }
  const auto [F, W] = get_F_W(n, edg, a);
  output_method(n, F, W, edg, val);
  output_ans(F, W, val, a);
}