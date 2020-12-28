#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<pair<int, ll>>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }
  vector<ll> ans(q, inf);
  vector<tuple<int, int, int>> qq;
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v)
      swap(u, v);
    qq.emplace_back(u, v, i);
  }
  vector<ll> dis(n + 1), vis(n + 1);
  function<void(int, int, int, vector<tuple<int, int, int>> &)> d =
      [&](int l, int r, int s, auto &ask) {
        fill(dis.begin() + l, dis.begin() + r + 1, inf);
        fill(vis.begin() + l, vis.begin() + r + 1, 0);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
        dis[s] = 0;
        Q.emplace(dis[s], s);
        while (!Q.empty()) {
          auto [_, u] = Q.top();
          Q.pop();
          if (vis[u])
            continue;
          vis[u] = 1;
          for (auto [v, w] : E[u]) {
            if (v < l || v > r)
              continue;
            if (dis[v] > dis[u] + w) {
              dis[v] = dis[u] + w;
              Q.emplace(dis[v], v);
            }
          }
        }
        for (auto &[u, v, id] : ask) {
          ans[id] = min(ans[id], dis[u] + dis[v]);
        }
      };
  function<void(int, int, vector<tuple<int, int, int>> &)> dfs =
      [&](int l, int r, auto &ask) {
        if (ask.empty())
          return;
        if (l > r) {
          return;
        }
        int mid = (l + r) / 2;
        vector<tuple<int, int, int>> L, R;
        for (auto &x : ask) {
          auto [u, v, id] = x;
          if (v <= mid) {
            L.emplace_back(x);
          } else if (u > mid) {
            R.emplace_back(x);
          }
        }
        dfs(l, mid, L);
        dfs(mid + 1, r, R);
        for (int i = max(l, mid - 5); i <= min(r, mid + 5); ++i) {
          d(l, r, i, ask);
        }
      };
  dfs(0, n - 1, qq);
  for (auto i : ans) {
    if (i >= inf) {
      cout << "-1\n";
    } else {
      cout << i << "\n";
    }
  }
}