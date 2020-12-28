#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m;
long long ans, a[maxn], b[maxn];
void dfs(int now, long long ma)
{
    if (ma + b[now] <= ans)
        return;
    ans = max(ans, ma);
    for (int i = now; i; i--)
        if (ma + a[i] <= m)
            dfs(i - 1, ma + a[i]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] > m)
        {
            n = i - 1;
            break;
        }
        b[i] = b[i - 1] + a[i];
    }
    dfs(n, 0);
    printf("%lld", ans);
    return 0;
}