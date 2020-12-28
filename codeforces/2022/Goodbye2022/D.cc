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
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  for (auto &i : b) {
    cin >> i;
    i--;
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n; ++i) {
    E[a[i]].emplace_back(b[i]);
    E[b[i]].emplace_back(a[i]);
  }
  vector<int> vis(n);
  int node = 0, edge = 0;
  bool self_loop = false;
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    node++;
    edge += (int)E[u].size();
    for (auto v : E[u]) {
      if (v == u)
        self_loop = true;
      if (!vis[v]) {
        dfs(v);
      }
    }
  };
  ll case_1 = 0, case_2 = 0;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      node = 0, edge = 0, self_loop = false;
      dfs(i);
      if (self_loop) {
        case_2++;
      } else {
        case_1++;
      }
      if (node * 2 != edge) {
        cout << "0\n";
        return;
      }
    }
  }
  cout << qpow(2, case_1) * qpow(n, case_2) % MOD << "\n";
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
