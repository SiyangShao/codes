#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e6 + 10;
array<int, N> col;
array<vector<int>, N> E;
void dfs(int u, int fa) {
  for (auto v : E[u]) {
    if (v == fa)
      continue;
    dfs(v, u);
  }
  if (col[u] == 1 || col[u] == 0)
    return;
  bool has_black = false;
  bool has_white = false;
  for (auto v : E[u]) {
    if (col[v] == 1) {
      has_black = true;
    }
    if (col[v] == 0) {
      has_white = true;
    }
  }
  if (!has_black) {
    return;
  }
  if (has_white) {
    return;
  }
  // need to color one.
  // either color yourself or color fa
  if (fa != -1 && col[fa] != 1) {
    col[fa] = 0;
  } else {
    col[u] = 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  fill(col.begin(), col.end(), -1);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    col[x - 1] = 1;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  dfs(0, -1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (col[i] == 0) {
      ans++;
    }
  }
  cout << ans << "\n";
}
