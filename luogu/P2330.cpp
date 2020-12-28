#include <bits/stdc++.h>
using namespace std;
int fa[301];
int n , m;
struct edge{
    int u ,v , w;
}a[100001];
bool cmp(edge x, edge y){
    return x.w<y.w;
}
void makeSet(int size){
    for(int i = 1 ; i<=size ; i++){
        fa[i]=i;
    }
    return;
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
int main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>n>>m;
    makeSet(n);
    for(int i = 1 ; i<= m ; i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+1+m,cmp);
    int mx=0 , t = 0;
    for(int i = 1 ; i<= m ; i++){
        int u = a[i].u , v =a[i].v;
        if(find(u)==find(v)){
            continue;
        }else{
            mx=max(mx,a[i].w);
            unionSet(u,v);
            t++;
        }
    }
    cout<<t<<" "<<mx<<"\n";
}