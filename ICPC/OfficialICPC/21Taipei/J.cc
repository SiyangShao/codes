#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

const ll Amx = 65535;
ll dp[Amx + 2][202];
ll a[18];

/*
  - dp[msk][k] := the largest permutation using only msk digits, with remainder k.
    dp[msk][k] --> dp[msk ^ (1ll << notbit)][(k * 10 + newNum) % k]

*/

void solve(){
  ll n,s,p,u;
  cin >> n >> s >> p;
  for(int i=0;i<s;i++) cin >> u;
  u = n - s - 1;
  ll ans =  ((s-1)*(n-1) + 2*(p-s)*(n-1) + (u-(p-s))*(n-1) + (n-p)*(p))*2;
  cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
