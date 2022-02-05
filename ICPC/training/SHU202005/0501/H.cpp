#include <bits/stdc++.h>
using namespace std;
const int N = 200000+10;
vector<int> E[N];
int vis[N];
int n , ans;
void dfs(int x){
    vis[x]=1;
    for(auto i : E[x]){
        //cout<<i<<":"<<E[i].size()<<" ";
        if(vis[i]==0&&E[i].size()>1){
            dfs(i);
        }else if(vis[i]==0&&E[i].size()==1){
            ans++;
        }
    }
}
int main(){
    cin>>n;
    for(int i = 1 , u , v; i<n; i++){
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1);
    //cout<<E[2].size()<<" ";
    if(E[1].size()==1){
        ans++;
    }
    cout<<ceil(ans/2.0);
}