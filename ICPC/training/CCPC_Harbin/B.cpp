#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    int dp[n+1];
    int a[n+1];
    memset(dp,0,sizeof dp);
    vector<vector<ll> > inv (101,vector<ll>());
    for(int i=1;i<=n;i++){
        cin >> a[i];
        inv[i].emplace_back(a[i],i);
    }
    ll maxans=0;
    for(int sum = 2;sum<=200;sum++){
        for(int i=1;i<=n;i++){
            dp[i]= max(dp[i],dp[i-1]);
            if(a[i]>=sum) continue;
            
            auto it = lower_bound(inv[sum-a[i]].begin(),inv[sum-a[i]].end(), i+1);
            if(it==inv[sum-a[i]].end()) continue;
            dp[*it] = max(dp[*it],dp[i-1]+1);
        }
        maxans=max(maxans,dp[n]);
    }
    cout << maxans << "\n";


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
  
    while (_--) {
        solve();
    }
}