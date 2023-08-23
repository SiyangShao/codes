#include <bits/stdc++.h>
using namespace std;
struct Tarjan_SCC {
  int n, edg_id, _t, sc_id;
  vector<vector<int>> E;
  // vector<pair<int, int>> edges;
  vector<int> dfn, low, in_scc;
  stack<int> st;
  vector<bool> in_st;
  Tarjan_SCC(int _n)
      : n(_n), E(_n), dfn(_n, -1), low(_n), in_scc(_n, -1), in_st(_n, false) {
    sc_id = edg_id = _t = 0;
  }
  void addEdge(int u, int v) {
    E[u].emplace_back(v);
    // E[v].emplace_back(edg_id);
    // edg_id++;
  }
  void dfs(int u) {
    low[u] = dfn[u] = _t++;
    st.emplace(u), in_st[u] = true;
    for (auto v : E[u]) {
      // auto v = edges[id].second;
      if (dfn[v] == -1) {
        dfs(v);
        low[u] = min(low[u], low[v]);
      } else if (in_st[v]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (dfn[u] == low[u]) {
      // vector<int> _scc;
      // _scc.clear();
      while (st.top() != u) {
        auto v = st.top();
        in_scc[v] = sc_id, in_st[v] = false;
        st.pop();
      }
      in_scc[u] = sc_id;
      // scc.emplace_back(_scc);
      sc_id++;
      st.pop(), in_st[u] = false;
    }
  }
  void solve() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1) {
        dfs(i);
      }
    }
  }
};
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
      ans += dfs(s, t, 1e9);
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  Tarjan_SCC G(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G.addEdge(u, v);
  }
  G.solve();
  int new_n = G.sc_id;
  dinic<int> H(new_n * 2 + 2);
  int S = new_n * 2, T = new_n * 2 + 1;
  // for (int i = 0; i < n; ++i) {
  //   cout << G.in_scc[i] << ' ';
  // }
  // cout << "\n";
  for (int u = 0; u < n; ++u) {
    for (auto v : G.E[u]) {
      int i = G.in_scc[u], j = G.in_scc[v];
      if (i != j) {
        H.addEdge(i + new_n, j, 1e9);
        // cout << i << " " << j << "\n";
      }
    }
  }
  int id = (int)H.edg.size();
  for (int i = 0; i < new_n; ++i) {
    H.addEdge(S, i + new_n, 1);
    H.addEdge(i, T, 1);
    H.addEdge(i, i + new_n, 1e9);
  }

  auto ans = H.solve(S, T);
  vector<int> col(new_n, -1);
  vector<vector<pair<int, int>>> E(new_n);
  vector<int> in(new_n, 0), out(new_n, 0);
  for (int i = 0; i < id; i += 2) {
    auto [u, v, f] = H.edg[i];
    u -= new_n;
    f = int(1e9) - f;
    if (f != 0) {
      // connect u->v
      // u and v is in the same color
      E[u].emplace_back(v, f);
      in[v] += f;
      out[u] += f;
    }
  }
  int c = 0;
  for (int t = 0; t < new_n; ++t) {
    for (int x = 0; x < new_n; ++x) {
      while (out[x] > in[x]) {
        int u = x;
        col[u] = c;
        while (out[u]) {
          auto it = prev(E[u].end());
          it->second--;
          auto nxt = it->first;
          if (it->second == 0) {
            E[u].pop_back();
          }
          out[u]--;
          col[nxt] = c;
          in[nxt]--;
          u = nxt;
        }
        c++;
      }
    }
  }
  for (int i = 0; i < new_n; ++i) {
    if (col[i] == -1) {
      col[i] = c++;
    }
  }
  // cerr << c << " " << ans << endl;
  assert(c == new_n - ans);
  // cout << ans << '\n';
  // cout << new_n - ans << "\n";
  for (int i = 0; i < n; ++i) {
    cout << col[G.in_scc[i]] + 1 << ' ';
  }
  cout << "\n";
}