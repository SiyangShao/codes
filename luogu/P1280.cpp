#include <bits/stdc++.h>
using namespace std;
vector<int>q[10010];
int dp[10010] , n , k;
int main(){
    cin>>n>>k;
    for(int i = 1  , j , tmp ; i<= k ; i++){
        cin>>j>>tmp;
        q[j].push_back(tmp);
    }
    for(int i = n ; i>=1 ; i--){
        if(q[i].size()==0){
            dp[i] = dp[i+1]+1;
        }else{
            for(auto j : q[i]){
                dp[i] = max(dp[i] , dp[i+j]);
            }
        }
    }
    cout<<dp[1];
}