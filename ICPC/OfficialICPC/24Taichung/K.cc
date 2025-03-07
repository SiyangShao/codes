#include <bits/stdc++.h>
using namespace std;
struct SCC {
  int n, _t, sc_id;
  vector<vector<int>> E;
  vector<int> dfn, low, in_scc;
  stack<int> st;
  vector<bool> in_st;
  SCC(int _n)
      : n(_n), E(_n), dfn(_n, -1), low(_n), in_scc(_n, -1), in_st(_n, false) {
    sc_id = _t = 0;
  }
  void addEdge(int u, int v) { E[u].emplace_back(v); }
  void dfs(int u) {
    low[u] = dfn[u] = _t++;
    st.emplace(u), in_st[u] = true;
    for (auto v : E[u]) {
      if (dfn[v] == -1)
        dfs(v), low[u] = min(low[u], low[v]);
      else if (in_st[v])
        low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
      while (st.top() != u) {
        auto v = st.top();
        in_scc[v] = sc_id;
        in_st[v] = false;
        st.pop();
      }
      in_scc[u] = sc_id;
      sc_id++;
      st.pop(), in_st[u] = false;
    }
  }
  void solve() {
    for (int i = 0; i < n; i++)
      if (dfn[i] == -1)
        dfs(i);
  }
  void clear_mem() {
    vector<int>().swap(dfn);
    vector<int>().swap(low);
    vector<bool>().swap(in_st);
  }
};
auto topoSort(int n, vector<vector<int>> &E) {
  vector<int> in(n);
  for (int i = 0; i < n; i++) {
    for (auto j : E[i]) {
      in[j]++;
    }
  }
  queue<int> Q;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0) {
      Q.emplace(i);
    }
  }
  vector<int> top(n);
  int cur = 0;
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    top[cur++] = u;
    for (auto v : E[u]) {
      in[v]--;
      if (in[v] == 0)
        Q.emplace(v);
    }
  }
  return top;
}
auto sol(int n, vector<vector<int>> &E, vector<int> &topo) {
  vector<bool> vis(n);
  vector<int> dp(n), nxt(n, -1);
  vector<vector<int>> chains;
  while (true) {
    vector<int> chain;
    for (int i = n - 1; i >= 0; --i) {
      auto u = topo[i];
      auto base = (vis[u] ? 0 : 1);
      dp[u] = base;
      nxt[u] = -1;
      for (auto v : E[u]) {
        if (dp[u] < base + dp[v]) {
          dp[u] = base + dp[v];
          nxt[u] = v;
        }
      }
    }
    auto u = (int)(max_element(dp.begin(), dp.end()) - dp.begin());
    while (u != -1) {
      if (!vis[u]) {
        chain.emplace_back(u);
        vis[u] = true;
      }
      u = nxt[u];
    }
    chains.emplace_back(chain);
    bool all_vis = true;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        all_vis = false;
        break;
      }
    }
    if (all_vis)
      break;
  }
  return chains;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  SCC E(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E.addEdge(u, v);
  }
  E.solve();
  E.clear_mem();
  set<pair<int, int>> edg;
  vector<int> sz(E.sc_id);
  for (int i = 0; i < n; ++i) {
    for (auto j : E.E[i]) {
      if (E.in_scc[i] == E.in_scc[j])
        continue;
      edg.emplace(E.in_scc[i], E.in_scc[j]);
    }
    sz[E.in_scc[i]]++;
  }
  vector<vector<int>>().swap(E.E);
  vector<vector<int>> G(E.sc_id);
  for (auto [u, v] : edg) {
    G[u].emplace_back(v);
  }
  set<pair<int, int>>{}.swap(edg);
  auto topo = topoSort(E.sc_id, G);
  auto chains = sol(E.sc_id, G, topo);
  auto chains_prefix = chains;
  auto chains_size = chains.size();
  vector<int> in_chain(E.sc_id);
  for (int i = 0; i < chains_size; i++) {
    for (int j = 0; j < chains[i].size(); j++) {
      in_chain[chains[i][j]] = i;
      chains_prefix[i][j] = sz[chains[i][j]];
      if (j != 0) {
        chains_prefix[i][j] += chains_prefix[i][j - 1];
      }
    }
  }
  vector<vector<int>> status(E.sc_id, vector<int>(chains_size, -1));
  vector<int> in_nodes(E.sc_id), out_nodes(E.sc_id);
  for (auto i : topo) {
    status[i][in_chain[i]]++;
    for (auto v : G[i]) {
      for (int j = 0; j < chains_size; j++) {
        status[v][j] = max(status[v][j], status[i][j]);
      }
    }
    for (int j = 0; j < chains_size; j++) {
      if (status[i][j] != -1) {
        in_nodes[i] += chains_prefix[j][status[i][j]];
      }
    }
  }
  for (int i = 0; i < E.sc_id; i++) {
    fill(status[i].begin(), status[i].end(), -1);
  }
  for (int i = 0; i < chains_size; i++) {
    reverse(chains[i].begin(), chains[i].end());
    for (int j = 0; j < chains[i].size(); j++) {
      chains_prefix[i][j] = sz[chains[i][j]];
      if (j != 0) {
        chains_prefix[i][j] += chains_prefix[i][j - 1];
      }
    }
  }
  reverse(topo.begin(), topo.end());
  for (auto i : topo) {
    for (auto v : G[i]) {
      for (int j = 0; j < chains_size; j++) {
        status[i][j] = max(status[v][j], status[i][j]);
      }
    }
    status[i][in_chain[i]]++;
    for (int j = 0; j < chains_size; j++) {
      if (status[i][j] != -1) {
        out_nodes[i] += chains_prefix[j][status[i][j]];
      }
    }
  }
  int min_diff = n * 2;
  vector<bool> special(E.sc_id);
  for (int i = 0; i < E.sc_id; i++) {
    min_diff = min(min_diff, abs(in_nodes[i] - out_nodes[i]));
  }
  for (int i = 0; i < E.sc_id; i++) {
    if (abs(in_nodes[i] - out_nodes[i]) == min_diff) {
      special[i] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (special[E.in_scc[i]]) {
      cout << i + 1 << " ";
    }
  }
  cout << "\n";
}
