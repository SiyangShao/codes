#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[50001], tmp, b[7];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        a[i] += (a[i - 1] + tmp) % 7;
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[a[i]] != 0)
        {
            continue;
        }
        for (int j = n; j > i; j--)
        {
            if (a[i] == a[j])
            {
                b[a[i]] = j - i;
                break;
            }
        }
    }
    sort(b, b + 7);
    printf("%d\n", b[6]);
    return 0;
}