#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, _, ans, fa[400010], vis[400010];
int a[400010], b[400010];
unordered_map<int, int> mpa, mpb;
inline int binpow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return res;
}
inline void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        vis[i] = 0;
    }
}
int find(int x) {
    if (x != fa[x]) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
inline void unionSet(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}
void dfs(int i) {
    vis[i] = 1;
    if (vis[mpb[a[i]]] == 0) {
        unionSet(mpb[a[i]], i);
        dfs(mpb[a[i]]);
    }
    if (vis[mpa[b[i]]] == 0) {
        unionSet(mpa[b[i]], i);
        dfs(mpa[b[i]]);
    }
}
signed main() {
    scanf("%lld", &_);
    while (_--) {
        scanf("%lld", &n);
        init();
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            mpa[a[i]] = i;
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &b[i]);
            mpb[b[i]] = i;
        }
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == 0) {
                dfs(i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (fa[i] == i) {
                ans++;
            }
        }
        int tmp = binpow(2, ans);
        printf("%lld\n", tmp);
    }
}