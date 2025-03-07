#include <bits/stdc++.h>

typedef long long ll;
const int mod = 998244353;
const int N = 49;

int T[31][N+1][N+1], res[N+1], nres[N+1];

inline int fc(int x, int y) {
  return x * 7 + y + 1;
}

int main() {
  int TT; scanf("%d", &TT);
  for (int i = 0; i < 7; ++i)
    for (int j = 0; j < 7; ++j) {
      T[0][fc(i, j)][fc(i, j)] = 50;
      if (i != 6) T[0][fc(i, j)][fc(i + 1, j)] = 1; else ++T[0][fc(i, j)][fc(i, j)];
      if (j != 6) T[0][fc(i, j)][fc(i, j + 1)] = 1; else ++T[0][fc(i, j)][fc(i, j)];
    }
  for (int t = 1; t < 31; ++t) {
    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= N; ++j)
        for (int k = 1; k <= N; ++k)
          T[t][i][k] = (1ll * T[t - 1][i][j] * T[t - 1][j][k] + T[t][i][k]) % mod;
  }
  while (TT--) {
    int n; scanf("%d", &n);
    memset(res, 0, sizeof(res));
    res[1] = 1, res[8] = 1;
    for (int i = 0; i < 31; ++i)
      if ((n >> i) & 1) {
        for (int j = 1; j <= N; ++j)
          nres[j] = 0;
        for (int j = 1; j <= N; ++j)
          for (int k = 1; k <= N; ++k)
            nres[j] = (1ll * res[k] * T[i][k][j] + nres[j]) % mod;
        for (int j = 1; j <= N; ++j)
          res[j] = nres[j];
      }
    printf("%d\n", res[N]);
  }
  return 0;
}
