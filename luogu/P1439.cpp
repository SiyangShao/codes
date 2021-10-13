#include <bits/stdc++.h>
using namespace std;
int a[100001] , n , mp[100001] , dp[100001] , len;
int main(){
    scanf("%d",&n);
    for(int i = 1  , tmp; i<= n ;i++){
        scanf("%d",&tmp);
        mp[tmp] = i;    
    }
    for(int i = 1 ,  tmp ; i<=n ; i++){
        scanf("%d",&tmp);
        a[i] = mp[tmp];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i = 1 ; i<=n ; i++){
        int l = 0 , r = len , mid;
        if(a[i]>dp[len]){
            dp[++len] = a[i];
        }else{
            while(l<r){
                mid = (l+r)/2;
                if(dp[mid]>a[i]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }
            dp[l]=min(a[i],dp[l]);
        }
    }
    cout<<len;
}