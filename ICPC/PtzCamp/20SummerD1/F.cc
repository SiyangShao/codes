#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 300010;
array<vector<int>, N> E;
array<int, N> dp;
array<set<pair<int, int>>, N> son;
void merge(int u, int v) {
  if (son[u].size() < son[v].size()) {
    swap(son[u], son[v]);
  }
  for (auto x : son[v]) {
    son[u].emplace(x);
  }
  son[v].clear();
}
void dfs(int u) {
  dp[u] = 1;
  for (auto v : E[u]) {
    dfs(v);
    son[u].emplace(dp[v], v);
  }
  // fi
  if (son[u].empty()) {
    return;
  }
  auto [fi, mx] = *son[u].rbegin();
  dp[u] += fi;
  son[u].erase(prev(son[u].end()));
  merge(u, mx);
  // se
  if (son[u].empty()) {
    return;
  }
  auto [se, semx] = *son[u].rbegin();
  dp[u] += se;
  son[u].erase(prev(son[u].end()));
  merge(u, semx);
}
auto solve() {
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int fa;
    cin >> fa;
    fa--;
    E[fa].emplace_back(i);
  }
  dfs(0);
  cout << dp[0] << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}