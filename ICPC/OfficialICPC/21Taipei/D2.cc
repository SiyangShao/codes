#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

/*
  - dp[msk][k] := the largest permutation using only msk digits, with remainder k.
    dp[msk][k] --> dp[msk ^ (1ll << notbit)][(k * 10 + newNum) % k]

*/


void solve(){
  int d,k;
  cin >> d >> k;
  ll a[d];
  FOR(i,0,d-1) cin >> a[i];
  int maxv = k*d*9;
  ii dp[maxv][d+1]; // first is val, second is bitset

  ll arr[d];
  ll p[d];
  arr[0]=1;
  p[0]=1;
  for(int i=1;i<d;i++) {
    arr[i]=(10*arr[i-1])%k;
    p[i] = p[i-1]*10;
  }
  for(int i=0;i<maxv;i++){
    for(int j=0;j<d+1;j++) dp[i][j] = ii(-1,0);
  }
  dp[0][0] = ii(0,0);
  for(int sec=0;sec<d;sec++){
    for(int i=0;i<maxv;i++){
      for(int j=0;j<d;j++){
        
        if(dp[i][sec].first == -1 || (dp[i][sec].second & (1<<j)) ) continue;
        
        if( dp[i + a[j]*arr[d-1-sec]] [sec+1].first < dp[i][sec].first + (a[j]*p[d-1-sec]) ){
          dp[i + a[j]*arr[d-1-sec]] [sec+1] = ii(
             dp[i][sec].first + (a[j]*p[d-1-sec]), 
             dp[i][sec].second + (1<<j)
          );
        }
        
      }
    }
  }
  int curre = -1;
  ll ans = -1;
  for(int i=0;i<maxv;i++){
    if( (i%k >= curre) && (dp[i][d].first > ans) ){
      curre=i%k;
      ans = dp[i][d].first;
    }
  }
  cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
