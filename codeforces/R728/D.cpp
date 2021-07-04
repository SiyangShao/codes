#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 210, mod = 1e9 + 7, LOGN = 8;
int dp[N][N];
inline int binpow(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        k >>= 1;
    }
    return res;
}
inline int fra(int a) { return binpow(a, mod - 2); }
vector<int> q[N];
int gra[N], mgra[N], g[N][LOGN], x[N];

void dfs(int v, int p = -1) {
    static int time = 0;
    x[v] = p == -1 ? 0 : x[p] + 1;
    gra[v] = time++;
    g[v][0] = p == -1 ? v : p;
    for (int k = 1; k < LOGN; k++)
        g[v][k] = g[g[v][k - 1]][k - 1];
    for (auto to : q[v]) {
        if (to != p) {
            dfs(to, v);
            g[to][0] = v;
        }
    }
    mgra[v] = time++;
}
inline bool isPar(int v, int u) { return gra[v] <= gra[u] && mgra[v] >= mgra[u]; }
inline int lca(int v, int u) {
    if (isPar(v, u))
        return v;
    if (isPar(u, v))
        return u;
    for (int k = LOGN - 1; k >= 0; k--) {
        if (!isPar(g[v][k], u))
            v = g[v][k];
    }
    return g[v][0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        q[v].push_back(u);
        q[u].push_back(v);
    }
    int modr = fra(2);
    for (int i = 1; i <= n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) * modr % mod;
    }
    int modn = fra(n);
    int ans = 0;
    for (int v = 0; v < n; v++) {
        dfs(v);
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                int l = lca(a, b);
                int p = dp[x[b] - x[l]][x[a] - x[l]] * modn % mod;
                if (p)
                    ans = (ans + p) % mod;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}