#include <bits/stdc++.h>
using namespace std;
int n , m;
int fa[10010];
void init(){
    for(int i = 1 ; i<= n ; i++){
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int z , x, y;
    init();
    while(m--){
        cin>>z>>x>>y;
        if(z==2){
            if(find(x)==find(y)){
                cout<<"Y\n";
            }else{
                cout<<"N\n";
            }
        }else{
            unionSet(x,y);
        }
    }
}