#include <iostream>
#include <cstdio>
using namespace std;
int a[101][101],n,m,f[101][101],ans;
int main()
{
    scanf("%d%d",&n,&m);//读入
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            scanf("%d",&a[i][j]);
            //因为只需用到i，j上方，左方，左上方的信息，读入同步处理
            if (a[i][j]==1) f[i][j]=min(min(f[i][j-1],f[i-1][j]),f[i-1][j-1])+1;
            ans=max(ans,f[i][j]);//同步更新答案
        }
    printf("%d\n",ans);
}