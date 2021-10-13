#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int t1[202], m1[202], f[202][202];
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> m1[i] >> t1[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= m1[i]; j--)
        {
            for (int k = t; k >= t1[i]; k--)
            {
                f[j][k] = max(f[j][k], f[j - m1[i]][k - t1[i]] + 1);
            }
        }
    }
    cout << f[m][t];
    return 0;
}