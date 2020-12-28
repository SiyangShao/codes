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
struct dsu {
public:
  dsu() : _n(0) {}
  explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y)
      return x;
    if (-parent_or_size[x] < -parent_or_size[y])
      std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0)
      return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int> &v) { return v.empty(); }),
        result.end());
    return result;
  }

private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;
};
constexpr ll N = 1010;
auto solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  dinic<ll> G(N);
  vector<ll> h(m);
  vector<vector<ll>> s(m);
  ll S = 0, T = N - 1;
  dsu DSU(N);
  for (ll i = 0; i < m; ++i) {
    cin >> h[i];
    ll sz;
    cin >> sz;
    s[i].resize(sz);
    for (auto &j : s[i]) {
      cin >> j;
      if (j == -1) {
        j = T;
      }
    }
    for (ll j = 0; j < sz; ++j) {
      DSU.merge(s[i][j], s[i][0]);
    }
  }
  if (!DSU.same(S, T)) {
    cout << "0\n";
    return;
  }
  ll ans = 0;
  ll t = 0;
  while (ans < k) {
    for (ll i = 0; i < m; ++i) {
      ll u = s[i][t % s[i].size()];
      ll v = s[i][(t + 1) % s[i].size()];
      if (u != S && u != T) {
        u += n * t;
      }
      if (v != S && v != T) {
        v += n * (t + 1);
      }
      G.addEdge(u, v, h[i]);
    }
    for (ll i = 1; i <= n; ++i) {
      G.addEdge(i + t * n, i + t * n + n, numeric_limits<ll>::max());
    }
    while (G.level(S, T)) {
      ans += G.dfs(S, T, numeric_limits<ll>::max());
    }
    t++;
  }
  cout << t << "\n";
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