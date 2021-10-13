#include <bits/stdc++.h>
using namespace std;
int n , m;
struct ob{
    int c,w;
}a[1000][3];
int f[100000];
int t;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1,v,p,q ; i<= m ; i++){
        cin>>v>>p>>q;
        if(q==0){
            a[i][0].c=v;
            a[i][0].w=p*v;
        }else{
            if(a[q][1].c==0){
                a[q][1].c=v;
                a[q][1].w=p*v;
            }else{
                a[q][2].c=v;
                a[q][2].w=p*v;
            }
        }
    }
    for(int i = 1;i<=m ; i++){
        for(int v = n ; v>=a[i][0].c&&a[i][0].c!=0 ; v--){
            f[v]=max(f[v],f[v-a[i][0].c]+a[i][0].w);
            if(v>=a[i][0].c+a[i][1].c){
                f[v]=max(f[v],f[v-a[i][0].c-a[i][1].c]+a[i][0].w+a[i][1].w);
            }
            if(v>=a[i][0].c+a[i][2].c){
                f[v]=max(f[v],f[v-a[i][0].c-a[i][2].c]+a[i][0].w+a[i][2].w);
            }
            if(v>=a[i][0].c+a[i][1].c+a[i][2].c){
                f[v]=max(f[v],f[v-a[i][0].c-a[i][1].c-a[i][2].c]+a[i][0].w+a[i][1].w+a[i][2].w);
            }
        }
    }
    cout<<f[n]<<"\n";
}