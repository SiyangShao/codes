#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int k;
    cin >> k;
    string s;
    cin >> s;
    const int n = 1 << k;
    int dp[2*n];
    memset(dp,0,sizeof(dp));
    for (int i = n; i < 2 * n; i++) {
        dp[i] = 1;
    }
    for (int i = n - 1; i >= 1; i--) {
        if(s[n-1-i]=='0'){
            dp[i]=dp[2*i+1];
        }else{
            if(s[n-i-1]=='1'){
                dp[i]=dp[2*i];
            }else{
                dp[i]=dp[2*i+1]+dp[2*i];
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        --p;
        s[p] = c;
        for(int i = n-1-p ; i!=0 ; i/=2){
            if(s[n-1-i]=='0'){
                dp[i]=dp[2*i+1];
            }else{
                if(s[n-1-i]=='1'){
                    dp[i]=dp[2*i];
                }else{
                    dp[i]=dp[2*i+1]+dp[2*i];
                }
            }
        }
        cout << dp[1] << "\n";
    }
    return 0;
}
