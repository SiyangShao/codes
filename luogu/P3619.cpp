#include <bits/stdc++.h>
using namespace std;
int ans[100010];
int n, m;
vector<int> q[100010];
void dfs(int x, int fa, int init) {
    for (auto i : q[x]) {
        if (i == fa) {
            continue;
        }
        if (ans[i] == 0) {
            ans[i] = init;
            dfs(i,x,init);
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d%d", &u, &v);
        q[v].push_back(u);
    }
    for(int i = n ; i>=1 ; i--){
        if(ans[i]==0){
            ans[i] = i;
            dfs(i,0,i);
        }
    }
    for(int i = 1 ; i<=n ; i++){
        printf("%d ",ans[i]);
    }
}