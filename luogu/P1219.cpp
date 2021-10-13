#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], x[100], y[100], n, l;
void print()
{
    if (n < 3)
    {
        for (int i = 0; i < l; i++)
            printf("%d ", a[i]+1);
        printf("\n");
    }
    n++;
}
void dfs(int q)
{
    if (q >= l)
    {
        print();
        return;
    }
    else
    {
        for (int i = 0; i < l; i++)
        {
            if (b[i] == 0 && x[i + q] == 0 && y[q - i + l] == 0)
            {
                a[q] = i;
                b[i] = 1;
                x[i + q] = 1;
                y[q - i + l] = 1;
                dfs(q + 1);
                b[i] = 0;
                x[i + q] = 0;
                y[q - i + l] = 0;
            }
        }
    }
}
int main()
{
    scanf("%d", &l);
    dfs(0);
    printf("%d\n", n);
    return 0;
}