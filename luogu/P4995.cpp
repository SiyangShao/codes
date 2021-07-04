#include<bits/stdc++.h>
using namespace std;
long long n,A[301],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>A[i];
    sort(A+1,A+n+1);//STL大法排序
    int q=0,p=n;//p,q分别记录接下来要跳的石头是那块
    while(q<p){
        ans+=pow((A[p]-A[q]),2);//计算跳一次后增加消耗的体力值
        q++;
        ans+=pow((A[q]-A[p]),2);//同上
        p--;
    }
    cout<<ans;//输出
    return 0;
}