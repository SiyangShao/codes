#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[1010];
int fa[1010];
int vis[1010];
void init() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
}
int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void unionSet(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)
		fa[x] = y;
}
int main(){
    cin>>n>>m;
    init();
    for(int i = 1 ; i<=m; i++){
        int x , y;
        char tmp;
        cin>>tmp>>x>>y;
        if(tmp=='F'){
            unionSet(x,y);
        }else{
            if(f[x]==0){
                f[x]=y;
            }else{
                unionSet(f[x],y);
            }
            if(f[y]==0){
                f[y]=x;
            }else{
                unionSet(x,f[y]);
            }
        }
    }
    for(int i = 1 ; i<= n ; i++){
        vis[find(i)]++;
    }
    int ans = 0;
    for(int i = 1; i<=n ; i++){
        if(vis[i]>=1){
            ans++;
        }
    }
    cout<<ans;
}