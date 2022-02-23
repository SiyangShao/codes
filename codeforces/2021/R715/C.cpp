#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , s[2010];
int dp[2010][2010];
signed main(){
    cin>>n;
    for(int i = 1 ; i<= n ; i++){
        cin>>s[i];
    }
    sort(s+1,s+1+n);
    for(int len = 1 ; len <n ; len++){
        for(int  l = 1 ; l+len <= n ;l++){
            int r = l+len;
            dp[l][r]=min(dp[l][r-1],dp[l+1][r])+s[r]-s[l];
        }
    }
    cout<<dp[1][n];
}