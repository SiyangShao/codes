#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+7;
int fa[maxn],val[maxn];
int n,m,les;
void init(){
    for(int i = 1 ; i<=n ; i++){
        fa[i]=i;
    }
}
int find(int x){
    if(fa[x] != x){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unionSet(int x , int y){
    x = find(x), y = find(y);
    fa[x] = y;
}

signed main(){
    scanf("%lld%lld",&n,&m);
    init();
    int minm = 0x3f3f3f3f;
    for(int i = 1 ; i<=n ; i++){
        scanf("%lld",&val[i]);
        if(minm > val[i]){
            minm = val[i];
            les = i;
        }
    }
    for(int i = 1,x,y; i<=m ; i++){
        scanf("%lld%lld",&x,&y);
        unionSet(x,y);
    }
    vector<int>ans;
    for(int i = 1 ; i<=n ; i++){
        if(find(i)==i){
            ans.push_back(i);
        }
    }
    bool flag = true;
    for(int i = 1 ; i<=n ; i++){
        if(val[i]!=minm){
            flag = false;
            break;
        }
    }
    if(flag){
        printf("-1");
        return 0;
    }else if(ans.size()==1){
        printf("%lld",minm);
        return 0;
    }
    
    
}