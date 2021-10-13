#include <bits/stdc++.h>
using namespace std;
int n , m;
int fa[1010];
void init(){
    for(int i =1 ; i<= n ; i++){
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
    x = find(x);
    y = find(y);
    fa[x]=y;
}
struct node{
    int x,  y , t;
}q[100001];
bool cmp(node x , node y){
    return x.t < y.t;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    init();
    for(int i = 0 ; i < m ; i++){
        cin>>q[i].x>>q[i].y>>q[i].t;
    }
    sort(q,q+m,cmp);
    for(int i = 0 ; i < m ; i++){
        unionSet(q[i].x,q[i].y);
        int tmp = find(1);
        bool flag = true;
        for(int j = 2 ; j <= n ; j++){
            if(find(j)!=tmp){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<q[i].t<<"\n";
            return 0;
        }
    }
    cout<<-1;
    return 0;
}