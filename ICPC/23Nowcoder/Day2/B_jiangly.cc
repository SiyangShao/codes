#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;
template <class T> struct MaxFlow {
  struct _Edge {
    int to;
    T cap;
    _Edge(int to, T cap) : to(to), cap(cap) {}
  };

  int n;
  std::vector<_Edge> e;
  std::vector<std::vector<int>> g;
  std::vector<int> cur, h;

  MaxFlow() {}
  MaxFlow(int n) { init(n); }

  void init(int n) {
    this->n = n;
    e.clear();
    g.assign(n, {});
    cur.resize(n);
    h.resize(n);
  }

  bool bfs(int s, int t) {
    h.assign(n, -1);
    std::queue<int> que;
    h[s] = 0;
    que.push(s);
    while (!que.empty()) {
      const int u = que.front();
      que.pop();
      for (int i : g[u]) {
        auto [v, c] = e[i];
        if (c > 0 && h[v] == -1) {
          h[v] = h[u] + 1;
          if (v == t) {
            return true;
          }
          que.push(v);
        }
      }
    }
    return false;
  }

  T dfs(int u, int t, T f) {
    if (u == t) {
      return f;
    }
    auto r = f;
    for (int &i = cur[u]; i < int(g[u].size()); ++i) {
      const int j = g[u][i];
      auto [v, c] = e[j];
      if (c > 0 && h[v] == h[u] + 1) {
        auto a = dfs(v, t, std::min(r, c));
        e[j].cap -= a;
        e[j ^ 1].cap += a;
        r -= a;
        if (r == 0) {
          return f;
        }
      }
    }
    return f - r;
  }
  void addEdge(int u, int v, T c) {
    g[u].push_back(e.size());
    e.emplace_back(v, c);
    g[v].push_back(e.size());
    e.emplace_back(u, 0);
  }
  T flow(int s, int t) {
    T ans = 0;
    while (bfs(s, t)) {
      cur.assign(n, 0);
      ans += dfs(s, t, std::numeric_limits<T>::max());
    }
    return ans;
  }

  std::vector<bool> minCut() {
    std::vector<bool> c(n);
    for (int i = 0; i < n; i++) {
      c[i] = (h[i] != -1);
    }
    return c;
  }

  struct Edge {
    int from;
    int to;
    T cap;
    T flow;
  };
  std::vector<Edge> edges() {
    std::vector<Edge> a;
    for (int i = 0; i < e.size(); i += 2) {
      Edge x;
      x.from = e[i + 1].to;
      x.to = e[i].to;
      x.cap = e[i].cap + e[i + 1].cap;
      x.flow = e[i + 1].cap;
      a.push_back(x);
    }
    return a;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<int, int>>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    u--, v--;
    adj[u].emplace_back(v, c);
    adj[v].emplace_back(u, c);
  }

  std::vector<int> a(m), b(m), x(m);
  int sum = 0;
  for (int i = 0; i < m; i++) {
    int y;
    std::cin >> a[i] >> b[i] >> x[i] >> y;
    a[i]--, b[i]--;
    x[i] = std::max(0, x[i] - y);
    sum += x[i];
  }

  int s = 0;
  int t = n + m;
  std::vector<std::tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    edges.emplace_back(s, n + i, x[i]);
  }

  std::vector<int> pc(n), parent(n, -1);

  std::vector<int> f(n), path(n);
  std::iota(f.begin(), f.end(), 0);

  std::function<int(int)> find = [&](int x) {
    if (f[f[x]] == f[x]) {
      return f[x];
    }
    find(f[x]);
    int e = t++;
    if (path[f[x]]) {
      edges.emplace_back(e, path[f[x]], inf);
    }
    edges.emplace_back(e, path[x], inf);
    path[x] = e;
    f[x] = f[f[x]];
    return f[x];
  };

  std::vector<std::vector<int>> v(n);
  for (int i = 0; i < m; i++) {
    v[a[i]].push_back(i);
    v[b[i]].push_back(i);
  }
  std::vector<bool> vis(m);

  auto dfs = [&](auto self, int x) -> void {
    for (auto [y, c] : adj[x]) {
      if (y == parent[x]) {
        continue;
      }
      pc[y] = c;
      parent[y] = x;
      self(self, y);
      f[y] = x;
      path[y] = y;
    }
    for (auto i : v[x]) {
      if (!vis[i]) {
        vis[i] = true;
        if (x == b[i]) {
          std::swap(a[i], b[i]);
        }
      } else if (x == b[i]) {
        int t = find(a[i]);
        edges.emplace_back(n + i, path[a[i]], inf);
        if (t != x) {
          v[t].push_back(i);
        }
      } else {
        find(b[i]);
        edges.emplace_back(n + i, path[b[i]], inf);
      }
    }
  };
  dfs(dfs, 0);

  for (int i = 1; i < n; i++) {
    edges.emplace_back(i, t, pc[i]);
  }

  MaxFlow<int> g(t + 1);
  for (auto [u, v, w] : edges) {
    std::cout << u << " " << v << " " << w << "\n";
    g.addEdge(u, v, w);
  }

  int ans = sum - g.flow(s, t);
  std::cout << ans << "\n";

  return 0;
}