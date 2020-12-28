#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int N = 60003 + 5, M = 225003 + 5;
int d[N];
struct flow {
  int cnt = 1, hd[N], nxt[M << 1], to[M << 1], limit[M << 1];
  void add(int u, int v, int w) {
    nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v, limit[cnt] = w;
    nxt[++cnt] = hd[v], hd[v] = cnt, to[cnt] = u, limit[cnt] = 0;
  }
  int T, dis[N], cur[N];
  long long dfs(int id, long long res) {
    if (id == T)
      return res;
    long long flow = 0;
    for (int i = cur[id]; i && res; i = nxt[i]) {
      cur[id] = i;
      int c = min(res, (long long)limit[i]), it = to[i];
      if (dis[id] + 1 == dis[it] && c) {
        int k = dfs(it, c);
        flow += k, res -= k, limit[i] -= k, limit[i ^ 1] += k;
      }
    }
    if (!flow)
      dis[id] = -1;
    return flow;
  }
  long long maxflow(int s, int t) {
    T = t;
    long long flow = 0;
    while (1) {
      queue<int> q;
      memcpy(cur, hd, sizeof(hd));
      memset(dis, -1, sizeof(dis));
      q.push(s), dis[s] = 0;
      while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = hd[t]; i; i = nxt[i])
          if (dis[to[i]] == -1 && limit[i])
            dis[to[i]] = dis[t] + 1, q.push(to[i]);
      }
      if (dis[t] == -1)
        return flow;
      flow += dfs(s, 1e18);
    }
  }
} G;
int n, m, s, t;
constexpr long long inf = 1e18;
using ll = long long;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--, t--;
  int SS = n, TT = n + 1;
  vector<ll> d(n);
  vector<ll> base(m);
  for (int i = 0; i < m; ++i) {
    int u, v, lower, upper;
    cin >> u >> v >> lower >> upper;
    u--, v--;
    G.add(u, v, upper - lower);
    base[i] = lower;
    d[u] -= lower;
    d[v] += lower;
  }
  int id = G.cnt + 1;
  ll ans = 0;
  constexpr ll inf = 1e16;
  G.add(t, s, inf);
  for (int i = 0; i < n; ++i) {
    if (d[i] == 0)
      continue;
    if (d[i] > 0) {
      ans += d[i];
      G.add(SS, i, d[i]);
    } else {
      G.add(i, TT, -d[i]);
    }
  }
  auto check = G.maxflow(SS, TT);
  if (check != ans) {
    cout << "please go home to sleep\n";
    return 0;
  }
  auto bs = G.limit[id ^ 1];
  for (int i = id; i <= G.cnt; ++i) {
    G.limit[i] = 0;
  }
  auto add = G.maxflow(t, s);
  cout << -add + bs << "\n";
}