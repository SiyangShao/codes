#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int K = 1e7 + 5;
bitset<K> can;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }
  vector<int> query(m);
  for (auto &i : query) {
    cin >> i;
  }
  vector<int> siz(n), mx(n), vis(n), dis(n), b(n);
  int root = -1;
  function<void(int, int, int)> getRoot = [&](int u, int fa, int tot) {
    siz[u] = 1;
    mx[u] = 0;
    for (auto [v, w] : E[u]) {
      if (v == fa || vis[v])
        continue;
      getRoot(v, u, tot);
      siz[u] += siz[v];
      mx[u] = max(siz[v], mx[u]);
    }
    mx[u] = max(mx[u], tot - siz[u]);
    if (root == -1 || mx[u] < mx[root]) {
      root = u;
    }
  };
  getRoot(0, 0, n);
  vector<int> vec;
  function<void(int, int, ll, int)> get_dis = [&](int u, int fa, int d,
                                                  int from) {
    vec.emplace_back(u);
    dis[u] = d;
    b[u] = from;
    for (auto [v, w] : E[u]) {
      if (v == fa || vis[v])
        continue;
      get_dis(v, u, d + w, from);
    }
  };
  function<void(int)> cal = [&](int u) {
    vec.clear();
    vec.emplace_back(u);
    dis[u] = 0, b[u] = u;
    for (auto [v, w] : E[u]) {
      if (vis[v])
        continue;
      get_dis(v, u, w, v);
    }
    sort(vec.begin(), vec.end(), [&](int x, int y) { return dis[x] < dis[y]; });
    for (auto i : query) {
      if (can[i])
        continue;
      auto l = vec.begin(), r = prev(vec.end());
      while (l < r) {
        if (dis[*l] + dis[*r] > i) {
          r--;
        } else if (dis[*l] + dis[*r] < i) {
          l++;
        } else if (b[*l] == b[*r]) {
          if (dis[*r] == dis[*(r - 1)]) {
            r--;
          } else {
            l++;
          }
        } else {
          can[i] = true;
          break;
        }
      }
    }
  };
  function<void(int)> dp = [&](int u) {
    vis[u] = 1;
    cal(u);
    for (auto [v, w] : E[u]) {
      if (vis[v])
        continue;
      root = -1;
      getRoot(v, 0, siz[v]);
      dp(root);
    }
  };
  dp(root);
  for (auto i : query) {
    cout << (can[i] ? "AYE" : "NAY") << "\n";
  }
}