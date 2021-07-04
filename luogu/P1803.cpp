#include <bits/stdc++.h> //（万能库）
struct px
{          //（定义一个结构体数组，分别储存开始时间和结束时间）
    int a; //（开始时间）
    int b; //（结束时间）
} x[2000000];
bool cmp(px x, px y)
{ //（不管开始时间，直接按照结束时间排序）
    return x.b < y.b;
}
using namespace std;
int main()
{
    int n, sum = 1, mi;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> x[i].a >> x[i].b; //（读入数据）
    sort(x + 1, x + n + 1, cmp); //（排序）
    mi = x[1].b;                 //（无脑记录第一个值）
    int j = 1;
    while (j <= n) //（未优化的超长循环）
    {
        j++;
        if (x[j].a >= mi)
        {          //（找到符合要求的比赛，记录，参加）
            sum++; //（计数）
            mi = x[j].b;
        }
    }
    cout << sum; //（输出）
    return 0;    //（功德圆满）
}