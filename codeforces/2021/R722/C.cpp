#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int _, n;
int l[MAXN], r[MAXN];
vector<int> q[MAXN];
long long dp[MAXN][2];
void dfs(int x, int fa) {
    for (auto i : q[x]) {
        if (i == fa) {
            continue;
        }
        dfs(i, x);
        dp[x][0] +=
            max(dp[i][0] + 1ll*(abs(l[i] - l[x])), dp[i][1] + 1ll*(abs(l[x] - r[i])));
        dp[x][1] +=
            max(dp[i][0] + 1ll*(abs(l[i] - r[x])), dp[i][1] + 1ll*(abs(r[x] - r[i])));
    }
}
signed main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        memset(q, 0, sizeof(q));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &l[i], &r[i]);
        }
        for (int i = 1, a, b; i < n; i++) {
            scanf("%d%d", &a, &b);
            q[a].push_back(b);
            q[b].push_back(a);
        }
        dfs(1, 0);
        printf("%lld\n", max(dp[1][0], dp[1][1]));
    }
}