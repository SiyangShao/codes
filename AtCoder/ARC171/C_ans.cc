#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 3010, mod = 998244353;
inline void Add(int &x, int y) { x = (x + y >= mod ? x + y - mod : x + y); }
inline void Sub(int &x, int y) { x = (x - y < 0 ? x - y + mod : x - y); }
int qmi(int a, int b) {
  int r = 1;
  for (; b; b >>= 1) {
    if (b & 1)
      r = (ll)r * a % mod;
    a = (ll)a * a % mod;
  }
  return r;
}
int jc[N], ny[N];
void prepare_C(int nn) {
  jc[0] = 1;
  for (int i = 1; i <= nn; i++)
    jc[i] = (ll)jc[i - 1] * i % mod;
  ny[nn] = qmi(jc[nn], mod - 2);
  for (int i = nn; i; i--)
    ny[i - 1] = (ll)ny[i] * i % mod;
}
int C(int x, int y) {
  if (x < y || y < 0)
    return 0;
  return (ll)jc[x] * ny[x - y] % mod * ny[y] % mod;
}
int n;
int head[N], ver[N << 1], ne[N << 1], idx = 2;
void add(int x, int y) { ver[idx] = y, ne[idx] = head[x], head[x] = idx++; }
int f[N], g[N], siz[N];

int s[N], t[N];
void dp(int x, int fa) {
  for (int i = head[x]; i; i = ne[i])
    if (ver[i] != fa) {
      dp(ver[i], x);
    }

  memset(s, 0, sizeof s);
  s[0] = 1;
  int now = 0;
  for (int i = head[x]; i; i = ne[i])
    if (ver[i] != fa) {
      for (int j = now; ~j; j--) {
        Add(s[j + 1], (ll)s[j] * f[ver[i]] % mod);
        s[j] = (ll)s[j] * g[ver[i]] % mod;
      }
      now++;
    }
  for (int i = 0; i <= now; i++) {
    Add(g[x], (ll)jc[i] * s[i] % mod);
    Add(f[x], (ll)jc[i + 1] * s[i] % mod);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    add(x, y), add(y, x);
  }
  prepare_C(n);

  dp(1, 0);

  cout << g[1];
}
