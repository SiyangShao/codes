#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , a[200010] , mex[200010] , dp[200010];
signed main(){
    scanf("%lld",&n);
    for(int i = 1 ; i<=n ; ++i){
        scanf("%lld",&a[i]);
        if(a[i]>mex[i-1]){
            mex[i] = a[i];
        }else{
            mex[i] = mex[i-1];
        }
    }
    dp[1] = a[1];
    for(int i = 2 ; i<=n ; ++i){
        dp[i] = dp[i-1]*2 - dp[i-2] + a[i]; 
    }
    for(int i = 1 ; i<=n ; ++i){
        int ans = mex[i]*i+dp[i];
        printf("%lld\n",ans);
    }
}