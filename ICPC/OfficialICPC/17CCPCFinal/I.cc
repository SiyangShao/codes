#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<int> col(n);
  vector<vector<pair<int, int>>> E(n);
  map<pair<int, int>, int> mp;
  vector<map<int, int>> deg(n);
  vector<int> in(n);
  vector<int> is_circle(n);
  for (int i = 0; i < n; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    if (u > v)
      swap(u, v);
    in[u]++, in[v]++;
    col[i] = c;
    mp[{u, v}] = i;
    E[u].emplace_back(v, i);
    E[v].emplace_back(u, i);
    deg[u][c]++;
    deg[v][c]++;
  }
  vector<int> vis(n);
  queue<int> Q;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 1) {
      vis[i] = 1;
      Q.emplace(i);
    }
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto [v, id] : E[u]) {
      if (vis[v])
        continue;
      in[v]--;
      if (in[v] == 1) {
        vis[v] = 1;
        Q.emplace(v);
      }
    }
  }
  // debug info
  // for(int i = 0 ; i < n; ++i){
  //   cout<<in[i]<<"\n";
  // }
  // cout<<"\n";

  for (int i = 0; i < n; ++i) {
    if (in[i] == 2) {
      for (auto [v, id] : E[i]) {
        if (in[v] == 2) {
          is_circle[id] = 1;
        }
      }
    }
  }
  map<int, int> circle_edg;
  for (int i = 0; i < n; ++i) {
    if (is_circle[i]) {
      circle_edg[col[i]]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (ll)deg[i].size();
  }
  while (m--) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    if (u > v)
      swap(u, v);
    int id = mp[{u, v}];
    if (c != col[id]) {
      if (is_circle[id]) {
        circle_edg[col[id]]--;
        if (circle_edg[col[id]] == 0) {
          circle_edg.erase(col[id]);
        }
        circle_edg[c]++;
      }
      ans -= (ll)deg[u].size() + (ll)deg[v].size();
      deg[u][col[id]]--;
      if (deg[u][col[id]] == 0) {
        deg[u].erase(col[id]);
      }
      deg[v][col[id]]--;
      if (deg[v][col[id]] == 0) {
        deg[v].erase(col[id]);
      }
      col[id] = c;
      deg[u][c]++, deg[v][c]++;
      ans += (ll)deg[u].size() + (ll)deg[v].size();
    }
    // output
    if (circle_edg.size() != 1) {
      cout << ans - n << "\n";
    } else {
      cout << ans - n + 1 << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  for (int i = 1; i <= _; ++i) {
    cout << "Case #" << i << ":\n";
    solve();
  }
}