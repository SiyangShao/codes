#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=2019;
vector<int> G[2][N];
int f[N];
int val[2][N][N],l[2][N],r[2][N],siz[2][N];
int x,n,a;
void dfs(int num,int x)
{
    if(x!=1) siz[num][x]=1;
    for(int i=0;i<G[num][x].size();++i)
    {
        int to=G[num][x][i];
        dfs(num,to);
        siz[num][x]+=siz[num][to];
        l[num][x]=min(l[num][x],l[num][to]);
        r[num][x]=max(r[num][x],r[num][to]); 
    } 
    val[num][l[num][x]][r[num][x]]=max(val[num][l[num][x]][r[num][x]],siz[num][x]);
}
void read() {
    cin>>n;
    for(int cnt=0; cnt<=1; ++cnt) {
        cin>>a;
        for(int i=1; i<=a; i++) l[cnt][i]=a+1,r[cnt][i]=0;
        for(int i=2; i<=a; ++i) {
            cin>>x;
            G[cnt][x].push_back(i);
        }
        for(int i=1; i<=n; ++i) {
            cin>>x;
            l[cnt][x]=r[cnt][x]=i;
        }
        dfs(cnt,1);
    }
}
int main() {
    read();
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
            f[j]=max(f[j],f[i-1]+max(val[0][i][j],val[1][i][j])), cout<<val[0][i][j]<<" "<<val[1][i][j]<<"\n";
    cout<<f[n];
    return 0;
}