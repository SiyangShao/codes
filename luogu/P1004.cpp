#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;
int a[maxn][maxn], n, f[maxn][maxn][maxn][maxn];
int main() {
  cin >> n;
  int x, y, v;
  while (cin >> x >> y >> v) {
    if (x == 0 && y == 0 && v == 0)
      break;
    a[x][y] = v;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int q = 1; q <= n; q++) {
        for (int p = 1; p <= n; p++) {
          f[i][j][q][p] =
              max(max(f[i - 1][j][q - 1][p], f[i - 1][j][q][p - 1]),
                  max(f[i][j - 1][q - 1][p], f[i][j - 1][q][p - 1])) +
              a[i][j] + a[q][p];
          if (i == q && j == p) {
            f[i][j][q][p] -= a[i][j];
          }
        }
      }
    }
  }
  cout << f[n][n][n][n] << "\n";
}
