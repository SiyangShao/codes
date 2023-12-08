#include <bits/stdc++.h>
using namespace std;
// v dom u if and only if for all w in pre(u), v dom w
// Dominator on DAG
constexpr int N = 65536;
int n;
array<vector<int>, N> E, revE, Tree;
array<int, N> in, dep, idom;
vector<int> tpn;
array<array<int, 17>, N> fth;
stack<int> st;
void topo() {
  st.emplace(0);
  for (int i = 1; i <= n; ++i)
    if (!in[i])
      E[0].push_back(i), revE[i].push_back(0), in[i]++;
  while (!st.empty()) {
    auto u = st.top();
    st.pop();
    tpn.emplace_back(u);
    for (auto v : E[u]) {
      in[v]--;
      if (in[v] == 0)
        st.emplace(v);
    }
  }
}
int lca(int u, int v) {
  if (u == v) return u;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 15; i >= 0; --i) 
    if (dep[fth[u][i]] >= dep[v]) u = fth[u][i];
  if (u == v)
    return u;
  for (int i = 15; i >= 0; --i)
    if (fth[u][i] != fth[v][i])
      u = fth[u][i], v = fth[v][i];
  return fth[u][0];
}
void build() {
  topo();
  for (auto u : tpn) {
    if (u == 0)
      continue;
    int v = revE[u][0];
    for (auto nv : revE[u])
      v = lca(v, nv);
    idom[u] = v, Tree[v].emplace_back(u), fth[u][0] = v;
    dep[u] = dep[v] + 1;
    for (int i = 1; i <= 15; ++i) 
      fth[u][i] = fth[fth[u][i - 1]][i - 1];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int v = 1; v <= n; ++v) {
    int u;
    while (cin >> u) {
      if (u == 0)
        break;
      E[u].emplace_back(v);
      revE[v].emplace_back(u);
      in[v]++;
    }
  }
  build();
}