#include <bits/stdc++.h>
/****
 * 本题为最小生成树模板
****/
using namespace std;
int fa[5001];
void init(){
    for(int i = 1 ; i <= 5000 ; i++){
        fa[i]=i;
    }
}
int find(int x){
    if(x!=fa[x]){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void unionSet(int x , int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}
struct Edge{
    int from , to , value;
}edge[200010];
bool cmp(Edge a , Edge b){
    return a.value < b.value;
}
int n , m , ans;
int main(){
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++){
        cin>>edge[i].from>>edge[i].to>>edge[i].value;
    }
    init();
    sort(edge,edge+m,cmp);
    for(int i = 0 ; i < m ; i++){
        int s = edge[i].from , t = edge[i].to , v = edge[i].value;
        if(find(s)==find(t)){
            continue;
        }
        ans+=v;
        unionSet(s,t);
    }
    cout<<ans<<"\n";
}