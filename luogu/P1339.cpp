#include <bits/stdc++.h>
using namespace std;
const int maxn = 2501;
int n , m , s, t;
int dis[maxn],g[maxn][maxn],vis[maxn];
int dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    for(int i = 0 ; i < n ; i++){
        int t = -1;
        for(int j = 1 ; j<= n ; j++){
            if(!vis[j]&&(t==-1||dis[t]>dis[j])){
                t=j;
            }
        }
        vis[t]=1;
        for(int j = 1 ; j <= n ; j++){
            dis[j]=min(dis[j],dis[t]+g[t][j]);
        }
    }
    
    if(dis[n]==0x3f3f3f3f) return -1;
    return dis[n];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s>>t;
    memset(g,0x3f,sizeof(g));
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        if(u==1){
            u=s;
        }else if(u==s){
            u=1;
        }else if(u==n){
            u=t;
        }else if(u==t){
            u=n;
        }
        if(v==1){
            v=s;
        }else if(v==s){
            v=1;
        }else if(v==n){
            v=t;
        }else if(v==t){
            v=n;
        }
        if(g[u][v]!=0)g[u][v]=g[v][u]=min(w,g[u][v]);
        else g[u][v]=g[v][u]=w;
    }
    cout<<dijkstra()<<"\n";
}