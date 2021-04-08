#include <bits/stdc++.h>
using namespace std;
struct node
{
    int i, j, num, f;
};
struct cmp
{
    bool operator()(node x, node y)
    {
        return x.num > y.num;
    }
};
priority_queue<node, vector<node>, cmp> q;
int n, m, maxn, maxj, maxi, w, top = 0, g[110][110], f[110][110];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = 1;
            cin >> g[i][j];
            node a;
            a.i = i;
            a.j = j;
            a.f = 0;
            a.num = g[i][j];
            q.push(a);
        }
    }
    while (!q.empty())
    {
        node now1 = q.top();
        int i = now1.i, j = now1.j, now = now1.num;
        q.pop();
        if (g[i - 1][j] < now)
            f[i][j] = max(f[i][j], f[i - 1][j] + 1);
        if (g[i + 1][j] < now)
            f[i][j] = max(f[i][j], f[i + 1][j] + 1);
        if (g[i][j - 1] < now)
            f[i][j] = max(f[i][j], f[i][j - 1] + 1);
        if (g[i][j + 1] < now)
            f[i][j] = max(f[i][j], f[i][j + 1] + 1);
        if (maxn < f[i][j])
            maxn = f[i][j];
    }
    cout << maxn << endl;
    return 0;
}
