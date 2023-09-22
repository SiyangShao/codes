#include <bits/stdc++.h>
using ll = long long;
#define int ll
const int maxn = 2e5 + 2, maxm = 5e5 + 2, inf = 1e9 + 1;

int n, m, rt, mn[maxn + 3], fa[maxn + 3], bel[maxn + 3], id[maxn + 3];

struct edge {

  int u, v, w;

} e[maxm + 3];

int chu_liu() {

  int ans = 0;

  while (true) {

    for (int i = 1; i <= n; i++) {

      mn[i] = inf, fa[i] = 0, bel[i] = 0, id[i] = 0;
    }

    for (int i = 1; i <= m; i++)
      if (e[i].u != e[i].v) {

        if (e[i].w < mn[e[i].v]) {

          mn[e[i].v] = e[i].w, fa[e[i].v] = e[i].u;
        }
      }

    for (int i = 1; i <= n; i++) {

      if (i != rt && !fa[i])
        return -1;
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
      if (i != rt) {

        ans += mn[i];

        int x = i;

        while (!bel[x] && x != rt) {

          bel[x] = i, x = fa[x];
        }

        if (bel[x] == i) {

          ++cnt;

          do {

            id[x] = cnt, x = fa[x];

          } while (!id[x]);
        }
      }

    if (!cnt) {

      break;
    }

    for (int i = 1; i <= n; i++) {

      if (!id[i])
        id[i] = ++cnt;
    }

    for (int i = 1; i <= m; i++) {

      int u = e[i].u, v = e[i].v;

      e[i].u = id[u], e[i].v = id[v];

      if (id[u] != id[v])
        e[i].w -= mn[v];
    }

    rt = id[rt];

    n = cnt;
  }

  return ans;
}

signed main() {
  int t;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &n, &m);
    rt = 1;
    for (int i = 1; i <= m; i++) {

      scanf("%lld %lld %lld", &e[i].u, &e[i].v, &e[i].w);
    }

    printf("%lld\n", chu_liu());
  }
  return 0;
}