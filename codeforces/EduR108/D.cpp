#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , a[5010] , b[5010] ,dp[5010][5010] , ans , s[5010];
int main(){
    cin>>n;
    for(int i = 1 ; i<= n ; i++){
        cin>>a[i];
    }
    for(int i = 1 ; i<= n ; i++){
        cin>>b[i];
    }
    for(int i = 1 ; i<= n ; i++){
       dp[i][i]=a[i]*b[i];
       s[i]=a[i]*b[i]+s[i-1];
    }
    ans=s[n];
    for(int i = n-1 ; i>=1 ; i--){
        for(int j = i+1 ;j<= n ; j++){
            dp[i][j] = dp[i+1][j-1]+a[i]*b[j]+a[j]*b[i];
        }
    }
    for(int i = 1 ; i<= n ; i++){
        for(int j = i+1 ; j<= n ; j++){
            ans = max(ans , s[i-1] + s[n] - s[j] + dp[i][j]);
        }
    }
    cout<<ans<<"\n";
}