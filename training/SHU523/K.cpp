#include <bits/stdc++.h>
using namespace std;
int dp[100010] , f[100010];
int n ,w , p,m,c,v;
int main(){
    while(~scanf("%d%d",&n,&w)){
        memset(dp,0,sizeof(dp));
        for(int i = 1 ; i<=n ; ++i){
            scanf("%d%d",&p,&m);
            memset(f,0,sizeof(f));
            for(int j = 1 ; j<=m ; ++j){
                scanf("%d%d",&c,&v);
                for(int k = w - p ; k>=c ; --k){
                    f[k] = max(f[k]+dp[k] , f[k-c]+dp[k-c]+v) - dp[k];
                }
            }
            for(int j = w ; j>=p ; --j){
                dp[j] = max(dp[j] , f[j-p]+dp[j-p]);
            }
        }
        printf("%d\n",dp[w]);
    }
}