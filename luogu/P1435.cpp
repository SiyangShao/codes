#include <bits/stdc++.h>
using namespace std;
string s;
string tmp;
int dp[1010][1010];
int main(){
    cin>>s;
    tmp=s;
    reverse(s.begin(),s.end());
    for(int i = 0 ; i < s.length() ; i++){
        for(int j = 0 ; j < s.length(); j++){
            if(s[i]==tmp[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }else{
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    cout<<s.length()-dp[s.length()][s.length()];
}