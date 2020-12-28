#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6;
struct node{
    int u ,v , w;
}a[maxn];
bool cmp(node x, node y){
    return x.w<y.w;
}
int x[2001] , y[2001],n,c,f[maxn],qt;
void init(){
    for(int i = 1 ; i<= n ; i++){
        f[i]=i;
    }
}
int find(int x){
    if(x!=f[x]){
        f[x]=find(f[x]);
    }
    return f[x];
}
void unionSet(int x , int y){
    x=find(x);
    y=find(y);
    f[x]=y;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>c;
    for(int i = 1 ; i<= n ; i++){
        cin>>x[i]>>y[i];
    }
    for(int i = 1 ; i<= n ; i++){
        for(int j = i+1 ; j<= n ; j++){
            int length = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            if(length>=c){
                a[qt].u=i,a[qt].v=j;
                a[qt++].w=length;
            }  
        }
    }
    init();
    sort(a,a+qt,cmp);
    int su = 0;
    for(int i = 0 ; i < qt ; i++){
        int u = a[i].u,v=a[i].v;
        if(find(u)!=find(v)){
            unionSet(u,v);
            su+=a[i].w;
        }
    }
    int root = find(1);
    for(int i = 1 ; i<= n ; i++){
        if(find(i)!=root){
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<su<<"\n";
}