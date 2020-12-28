#include <bits/stdc++.h>
using namespace std;
struct line
{
    int a, b, s;
} x[20010];

int main()
{
    int n, d[20010][2];
    memset(d,0,sizeof(d));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i].a >> x[i].b;
        x[i].s = abs(x[i].a - x[i].b);
    }
    d[1][0] = x[1].b+x[1].s-1;d[1][1]=x[1].b-1;
    for (int i = 2; i <= n; i++)
    {
        d[i][0] = min(d[i - 1][0] + 1 + abs(x[i].b - x[i - 1].a) + x[i].s, d[i - 1][1] + 1 + abs(x[i].b - x[i - 1].b) + x[i].s);
        d[i][1] = min(d[i - 1][0] + 1 + abs(x[i].a - x[i - 1].a) + x[i].s, d[i - 1][1] + 1 + abs(x[i].a - x[i - 1].b) + x[i].s);
    }
    cout<<min(n-x[n].b+d[n][1],n-x[n].a+d[n][0])<<endl;
}