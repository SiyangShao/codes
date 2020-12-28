#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

const ll Amx = 65535;

/*
  - dp[msk][k] := the largest permutation using only msk digits, with remainder k.
    dp[msk][k] --> dp[msk ^ (1ll << notbit)][(k * 10 + newNum) % k]

*/

void solve() {
  int d, k; 
  cin >> d >> k;
  int A = (1ll << d) ;
  ll dp[A + 1][202];
  int a[d];

  for(int i=0;i<d;i++) cin >> a[i];

  memset(dp,-1,sizeof dp);

  dp[0][0] = 0;
  for(int i=0;i<A;i++){
    for(int re=0;re<k;re++){
      for(int j=0;j<d;j++){
        if(dp[i][re] == -1 || (i&(1<<j)) ) continue;
        chkmax(dp[i+(1<<j)][(re*10 + a[j])%k], (dp[i][j]*10 +a[j]) );
        cout << i << " "<<"TEST\n";
      }
    }
  }
  
  for(int i=k-1;i>=0;i--){
    if(dp[A-1][i]!=-1){
      cout << dp[A][i] << " ";
      return;
    }
  }
  

  

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}