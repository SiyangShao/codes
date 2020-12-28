#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
  int n;
  vector<int> fa;
  DSU(int _) : n(_), fa(_) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  vector<ll> add(n), sub(n);
  int cur = 0;
  map<ll, int> amp, smp;
  for (int i = 0; i < n; ++i) {
    add[i] = i + a[i];
    if (!amp.contains(add[i])) {
      amp[add[i]] = cur++;
    }
    sub[i] = i - a[i];
    if (!smp.contains(sub[i])) {
      smp[sub[i]] = cur++;
    }
  }
  vector<vector<int>> E(cur);
  DSU dsu(cur);
  vector<pair<int, int>> edg(n);
  for (int i = 0; i < n; ++i) {
    edg[i] = {amp[add[i]], smp[sub[i]]};
    dsu.merge(edg[i].first, edg[i].second);
    E[amp[add[i]]].emplace_back(i);
    E[smp[sub[i]]].emplace_back(i);
  }
  vector<int> num_of_edges(cur);
  for (int i = 0; i < n; ++i) {
    auto [u, v] = edg[i];
    num_of_edges[dsu.find(u)]++;
  }
  for (auto i : num_of_edges) {
    if (i & 1) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  vector<int> vis(cur);
  vector<set<int>> nxt(cur);
  vector<pair<int, int>> ans;
  function<void(int, int, int)> dfs = [&](int u, int fa, int fa_id) {
    vis[u] = 1;
    for (auto id : E[u]) {
      auto v = u ^ edg[id].first ^ edg[id].second;
      if (v == fa)
        continue;
      nxt[u].emplace(id);
      if (!vis[v]) {
        dfs(v, u, id);
      }
    }
    if (nxt[u].size() % 2 == 0) {
      while (!nxt[u].empty()) {
        auto fi = *nxt[u].begin();
        nxt[u].erase(nxt[u].begin());
        auto se = *nxt[u].begin();
        nxt[u].erase(nxt[u].begin());
        ans.emplace_back(fi, se);
      }
    } else {
      assert(u != fa);
      nxt[fa].erase(fa_id);
      auto c = *nxt[u].begin();
      ans.emplace_back(fa_id, c);
      nxt[u].erase(nxt[u].begin());
      while (!nxt[u].empty()) {
        auto fi = *nxt[u].begin();
        nxt[u].erase(nxt[u].begin());
        auto se = *nxt[u].begin();
        nxt[u].erase(nxt[u].begin());
        ans.emplace_back(fi, se);
      }
    }
  };
  for (int i = 0; i < cur; ++i) {
    if (!vis[i]) {
      dfs(i, i, -1);
    }
  }
  for (auto &[u, v] : ans) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}