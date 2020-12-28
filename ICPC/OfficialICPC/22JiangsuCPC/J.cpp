#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,v) for(auto i:v)
#define rep(i,a,b) for(int i=(a);i<(b);i++)

__int128 MOD = 1;

map<__int128,__int128> dp;

inline __int128 mod(__int128 u, __int128 v) {
    while (u >= v) u -= v;
    return u;
}

__int128 recur(__int128 n){
    if(n == (__int128)0 || n == (__int128)1) return (__int128)1;
    if(dp.find(n) != dp.end()) return dp[n];
    n -= (__int128)1;
    if (n % 2){
        return dp[n+(__int128)1] = mod(mod(recur(n / (__int128)2) * recur(n / (__int128)2 + (__int128)1), MOD) * (__int128)2, MOD);
    }
    else{
        return dp[n+(__int128)1] = mod(recur(n / (__int128)2) * recur(n / (__int128)2), MOD);
    }
}

void solve(){
   unsigned long long n2;

   cin >> n2;
   ll n = (ll)n2;
   ll ans = recur(n) % MOD;

   cout << (unsigned long long)ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    rep(i,0,64) MOD*=(__int128)2;
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
}