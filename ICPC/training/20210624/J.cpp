#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+10;
int n , m;
vector<int> q[maxn];

int nut[maxn] , vis[maxn];
void dfs(int x , int fa){
    for(auto i : q[x]){
        if(i==fa){
            continue;
        }
        if(nut[i]==0){
            vis[i]=1;
            dfs(i,x);
        }else{
            int cnt = 0;
            for(auto j : q[i]){
                if(j!=x&&nut[j]!=1){
                    cnt++;
                }
            }
            if(cnt >=2){
                vis[i]=1;
                dfs(i,x);
            }else if(cnt == 1){
                for(auto j : q[i]){
                    if(j!=x&&nut[j]!=1){
                        nut[j] = 1;
                    }
                }
                vis[i]=1;
                dfs(i,x);
            }
        }
    }
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i = 1 , a , b ; i<n ; ++i){
        scanf("%lld %lld",&a,&b);
        q[a].push_back(b);
        q[b].push_back(a);
    }
    for(int i = 1 , a ; i <=m ; ++i){
        scanf("%lld",&a);
        nut[a] = 1;
    }
    dfs(1,0);
    vis[1]=1;
    int ans = 0;
    for(int i = 1 ; i<=n ; i++){
        if(vis[i]==1){
            ans++;
        }
    }
    printf("%lld",ans);
}