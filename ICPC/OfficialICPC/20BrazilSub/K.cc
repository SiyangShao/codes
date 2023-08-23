#include <bits/stdc++.h>
using namespace std;
constexpr int P = 110;
array<array<int, P>, P> matrix;
bool GaussElimination(int n) {
  int r, c;
  for (r = 0, c = 0; c < n; c++) {
    int t = r;
    for (int i = r; i < n; i++)
      if (matrix[i][c]) {
        t = i;
        break;
      }
    if (!matrix[t][c])
      continue;

    for (int i = c; i <= n; i++)
      swap(matrix[t][i], matrix[r][i]);
    for (int i = r + 1; i < n; i++)
      if (matrix[i][c])
        for (int j = c; j <= n; j++)
          matrix[i][j] ^= matrix[r][j];
    r++;
  }
  if (r < n) {
    for (int i = r; i < n; i++)
      if (matrix[i][n])
        return false;
  }
  return true;
}
auto solve() {
  int p, f;
  cin >> p >> f;
  vector<vector<int>> E(p);
  for (int i = 0; i < f; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  for (int i = 0; i < p; ++i) {
    for (auto v : E[i]) {
      matrix[i][v] = 1;
    }
    if (E[i].size() % 2 == 0) {
      matrix[i][p] = 1;
    } else {
      matrix[i][p] = 0;
      matrix[i][i] = 1;
    }
  }
  if (GaussElimination(p)) {
    cout << "Y\n";
  } else {
    cout << "N\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}