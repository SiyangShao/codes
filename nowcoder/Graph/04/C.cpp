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
auto solve() {
  int n;
  cin >> n;
  vector<int> s(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  if (n == 1) {
    cout << "1\n1\n1\n";
    return;
  }
  vector<int> dp(n + 1, 0);
  dinic<int> G(n * 2 + 2);
  auto in = [&](int u) { return u * 2 - 1; };
  auto out = [&](int u) { return u * 2; };
  for (int i = 1; i <= n; ++i) {
    dp[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (s[j] <= s[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  // S-> in(a) - > out(a) ->b->c->d->e -> T dp[a] == 1, dp[b] == 2, dp[c] ==
  // 3, dp[d] == 4, dp[e] == 5
  int ans = *max_element(dp.begin(), dp.end());
  cout << ans << "\n";
  int S = 0, T = n * 2 + 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (dp[j] == dp[i] + 1 && s[j] >= s[i]) {
        G.addEdge(out(i), in(j), 1);
      }
    }
    G.addEdge(in(i), out(i), 1);
    if (dp[i] == 1) {
      G.addEdge(S, in(i), 1);
    }
    if (dp[i] == ans) {
      G.addEdge(out(i), T, 1);
    }
  }
  int bs = G.solve(S, T);
  // x[0] && x[n-1]
  G.addEdge(in(1), out(1), numeric_limits<int>::max());
  G.addEdge(in(n), out(n), numeric_limits<int>::max());
  G.addEdge(S, in(1), numeric_limits<int>::max());
  if (dp[n] == ans) {
    G.addEdge(out(n), T, numeric_limits<int>::max());
  }
  cout << bs << "\n";
  bs += G.solve(S, T);
  cout << bs << "\n";
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