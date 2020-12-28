#include <bits/stdc++.h>
using namespace std;
const int maxn=5005;
int fa[maxn],ranki[maxn];
int n , m , p;
inline void init(){
    for(int i = 1 ; i<= n ;i++){
        fa[i]=i;
        ranki[i]=1;
    }
}
int find(int x){
    return x==fa[x] ? x:(fa[x]=find(fa[x]));
}
inline void merge(int i , int j){
    int x = find(i) , y = find(j);
    if(ranki[x]<=ranki[y]){
        fa[x]=y;
    }else{
        fa[y]=x;
    }
    if(ranki[x]==ranki[y]&&x!=y){
        ranki[y]++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>p;
    init();
    for(int i = 0 , a , b ; i < m ; i++){
        cin>>a>>b;
        merge(a,b);
    }
    for(int i = 0 ,a,b;  i<p ; ++i){
        cin>>a>>b;
        if(find(a)==find(b)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}