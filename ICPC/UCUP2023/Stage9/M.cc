#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<int> b(n - 1);
  vector<int> vis(n);
  for (auto &i : b) {
    cin >> i;
    i--;
    vis[i] = 1;
  }
  int rt = 0;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      rt = i;
      break;
    }
  }
  vector<int> fa(n, -1);
  function<void(int)> dfs = [&](int u) {
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
      fa[v] = u;
      dfs(v);
    }
  };
  dfs(rt);
  vector<ll> white(n), black(n);
  ll ans = 0, edg_num = 0;
  vector<pair<int, int>> edg;
  function<void(int)> dp = [&](int u) {
    int in = 0;
    for (auto v : E[u]) {
      if (!vis[v])
        in++;
      if (v == fa[u])
        continue;
      if (vis[u] == vis[v]) {
        if (vis[u] == 0) {
          edg_num++;
        } else {
          edg_num += 2;
        }
      } else {
        edg_num += 2;
      }
      dp(v);
    }
    if (!vis[u]) {
      return;
    }
    black[u] = in;
    white[u] = 1;
    ll sum_black = 0;
    stack<ll> Q;
    for (auto v : E[u] | ranges::views::reverse) {
      if (v == fa[u])
        continue;
      if (!vis[v])
        continue;
      Q.emplace(white[u]);
      white[u] = white[u] * (white[v] + black[v]) % MOD;
    }
    ll lef = 1;
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
      if (!vis[v])
        continue;
      sum_black = (sum_black + lef * Q.top() % MOD * black[v] % MOD);
      lef = lef * (white[v] + black[v]) % MOD;
      Q.pop();
      if (sum_black >= MOD)
        sum_black -= MOD;
    }
    black[u] = white[u] * in % MOD;
    black[u] += sum_black;
    if (black[u] >= MOD)
      black[u] -= MOD;
    if (!vis[fa[u]]) {
      ans = (ans * black[u]) % MOD;
    }
  };
  fill(vis.begin(), vis.end(), 0);
  int should_edg = n - 1;
  for (auto u : b) {
    should_edg++;
    edg_num = 0;
    vis[u] = 1;
    ans = 1;
    dp(rt);
    cout << ans * qpow(2, edg_num - should_edg) % MOD << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solve();
}