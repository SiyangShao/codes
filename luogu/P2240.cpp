#include <bits/stdc++.h>
using namespace std;
struct Q
{
    double m, v, mv;
};
bool cam(Q x, Q y)
{
    return x.mv > y.mv;
}
int main()
{
    int n;
    double t, sum = 0;
    cin >> n >> t;
    Q a[110];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].m >> a[i].v;
        a[i].mv = a[i].v / a[i].m;
    }
    sort(a, a + n, cam);
    for (int i = 0; i < n; i++)
    {
        if (t - a[i].m >= 0)
        {
            sum += a[i].v;
            t -= a[i].m;
        }
        else
        {
            sum += t * a[i].mv;
            break;
        }
    }
    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}