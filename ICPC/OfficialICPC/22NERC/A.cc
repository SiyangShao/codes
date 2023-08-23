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
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
  }
  auto dfs(int u, int t, Flow flow) {
    if (u == t)
      return flow;
    Flow sum = 0;
    while (cur[u] < (int)E[u].size() && flow > 0) {
      auto id = E[u][cur[u]];
      auto [_, v, f] = edg[id];
      auto c = min(flow, f);
      if (d[u] + 1 == d[v] && c > 0) {
        auto add = dfs(v, t, c);
        sum += add, flow -= add, edg[id].f -= add, edg[id ^ 1].f += add;
      }
      cur[u]++;
    }
    if (cur[u] > 0)
      cur[u]--;
    if (!sum)
      d[u] = -1;
    return sum;
  }
  bool level(int s, int t) {
    fill(d.begin(), d.end(), -1);
    fill(cur.begin(), cur.end(), 0);
    queue<int> Q;
    Q.emplace(s);
    d[s] = 0;
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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> mp(n);
  for (auto &i : mp) {
    cin >> i;
  }
  vector<vector<int>> document(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == '1') {
        document[j].emplace_back(i);
      }
    }
  }
  dinic<long long> G(m * 2 + 2);
  int S = m * 2, T = m * 2 + 1;
  vector<int> real_id(m);
  iota(real_id.begin(), real_id.end(), 0);
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      if (document[i].size() >= document[j].size()) {
        if (includes(document[i].begin(), document[i].end(),
                     document[j].begin(), document[j].end())) {
          G.addEdge(j, i + m, 1);
        }
      } else {
        if (includes(document[j].begin(), document[j].end(),
                     document[i].begin(), document[i].end())) {
          G.addEdge(i, j + m, 1);
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    G.addEdge(S, i, 1);
    G.addEdge(i + m, T, 1);
  }
  auto ans = G.solve(S, T);
  cout << m - ans << "\n";
  const auto &E = G.E;
  const auto &edg = G.edg;
  vector<int> nxt(m, -1), prev(m, -1);
  vector output(n, vector<int>(m - ans, 1));
  for (int u = 0; u < m; ++u) {
    for (auto id : E[u]) {
      auto [_, v, f] = edg[id];
      if (v != S && f == 0) {
        nxt[u] = v - m;
        prev[v - m] = u;
        break;
      }
    }
  }
  vector<int> col(m), val(m);
  int cur_col = 1;
  function<void(int, int, int)> color = [&](int u, int c, int v) {
    if (u == -1)
      return;
    col[u] = c;
    val[u] = v;
    for (auto i : document[u]) {
      output[i][c - 1] = v;
    }
    color(prev[u], c, v + 1);
  };
  for (int i = 0; i < m; ++i) {
    if (nxt[i] == -1) {
      color(i, cur_col, 2);
      cur_col++;
    }
  }
  assert(cur_col - 1 == m - ans);
  for (auto &i : col) {
    cout << i << " ";
  }
  cout << "\n";
  for (auto &i : val) {
    cout << i << " ";
  }
  cout << "\n";
  for (auto &i : output) {
    for (auto &j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}