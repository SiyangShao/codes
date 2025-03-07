#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto check(vector<vector<ll>> &A, vector<vector<ll>> &B, int n, int m) {
  vector<vector<int>> E(n + m);
  queue<int> Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] != B[i][j]) {
        if (A[i][j] == 0) {
          Q.emplace(n + j);
        } else {
          Q.emplace(i);
        }
      }
      if (B[i][j] == 0) {
        // do a i after j
        E[n + j].emplace_back(i);
      } else {
        // do a j after i
        E[i].emplace_back(n + j);
      }
    }
  }
  vector<int> vis(n + m, 0);
  auto dfs = [&](auto self, auto u) {
    if (vis[u] == 2)
      return true;
    if (vis[u] == 1)
      return false;
    vis[u] = 1;
    bool result = true;
    for (auto v : E[u]) {
      if (vis[v] == 1) {
        return false;
      }
      if (vis[v] == 2) {
        continue;
      }
      result = result && self(self, v);
    }
    vis[u] = 2;
    return result;
  };
  while (!Q.empty()) {
    auto u = Q.front();
    if (dfs(dfs, u)) {
      Q.pop();
    } else {
      return false;
    }
  }
  return true;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> A(n, vector<ll>(m)), B(n, vector<ll>(m));
  for (auto &i : A)
    for (auto &j : i)
      cin >> j;
  for (auto &i : B)
    for (auto &j : i)
      cin >> j;
  auto tmpA = A;
  auto tmpB = B;
  for (int k = 0; k < 32; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        tmpA[i][j] = (A[i][j] >> k) & 1;
        tmpB[i][j] = (B[i][j] >> k) & 1;
      }
    }
    if (!check(tmpA, tmpB, n, m)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
