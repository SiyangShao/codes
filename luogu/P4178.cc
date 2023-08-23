#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<pair<int, ll>>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }
  ll k;
  cin >> k;
  vector<int> siz(n), vis(n), mxp(n);
  int root = -1;
  ll ans = 0;
  function<void(int, int, int)> changeRoot = [&](int u, int fa, int tot) {
    siz[u] = 1;
    mxp[u] = 0;
    for (auto [v, w] : E[u]) {
      if (v == fa || vis[v])
        continue;
      changeRoot(v, u, tot);
      siz[u] += siz[v];
      mxp[u] = max(mxp[u], siz[v]);
    }
    mxp[u] = max(mxp[u], tot - siz[u]);
    if (root == -1 || mxp[root] > mxp[u]) {
      root = u;
    }
  };
  vector<int> vec;
  vector<ll> col(n), f(n), dis(n);
  function<void(int, int)> getdis = [&](int u, int pre) {
    vec.emplace_back(u);
    col[u] = col[pre];
    f[col[u]]++;
    for (auto [v, w] : E[u]) {
      if (v == pre || vis[v])
        continue;
      dis[v] = dis[u] + w;
      getdis(v, u);
    }
  };
  function<ll(int)> cal = [&](int u) {
    dis[u] = 0;
    vec.clear();
    vec.emplace_back(u);
    col[u] = u, f[col[u]] = 1;
    for (auto [v, w] : E[u]) {
      if (vis[v])
        continue;
      col[v] = v, dis[v] = w;
      f[col[v]] = 0;
      getdis(v, v);
    }
    sort(vec.begin(), vec.end(),
         [&](auto x, auto y) { return dis[x] < dis[y]; });
    auto l = vec.begin(), r = prev(vec.end());
    ll res = 0;
    while (l < r) {
      while (l < r && dis[*l] + dis[*r] <= k) {
        res += (r - l) + 1 - f[col[*l]];
        f[col[*l]]--;
        l++;
      }
      f[col[*r]]--;
      r--;
    }
    return res;
  };
  function<void(int)> dp = [&](int u) {
    vis[u] = 1;
    ans += cal(u);
    for (auto [v, w] : E[u]) {
      if (vis[v])
        continue;
      root = -1;
      changeRoot(v, v, siz[v]);
      dp(root);
    }
  };
  changeRoot(0, 0, n);
  dp(root);
  cout << ans << "\n";
}