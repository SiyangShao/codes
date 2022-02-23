#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[200010][2];
int t;
string s;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        memset(dp, 0, sizeof(dp));
        if (s[0] == '0') {
            dp[0][0] = 1;
        } else if (s[0] == '1') {
            dp[0][1] = 1;
        } else {
            dp[0][0] = 1;
            dp[0][1] = 1;
        }
        int ans = max(dp[0][0],dp[0][1]);
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == '?') {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = dp[i - 1][0] + 1;
            } else if (s[i] == '1') {
                dp[i][1] = dp[i - 1][0] + 1;
            } else {
                dp[i][0] = dp[i - 1][1] + 1;
            }
            ans+=max(dp[i][0],dp[i][1]);
        }
        cout<<ans<<"\n";
    }
}