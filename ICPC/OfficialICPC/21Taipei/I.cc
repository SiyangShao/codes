#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

/*
  - dp[msk][k] := the largest permutation using only msk digits, with remainder k.
    dp[msk][k] --> dp[msk ^ (1ll << notbit)][(k * 10 + newNum) % k]

*/


void solve(){
  int s;
  cin >> s;
ll left[s];
  ll right[s];
  ll l=0,r=0;
  FOR(i,0,s-1) {
    cin >> left[i];
    l += (i+1)*left[i];
  }
  FOR(i,0,s-1) {
    cin >> right[i];
    r += (i+1)*right[i];
  }
  if(l>r || r-l>10100){
    cout << "-1\n";
    return;
  }
  else if(l==r) {
    cout << "0\n";
    return;
  }
  
  int req = r-l;
  req = min(req,5050);
  bool dp[req+1][s+1];
  bool dp2[req+1][s+1];
  memset(dp,0,sizeof dp);
  memset(dp2,0,sizeof dp2);
  dp[0][0]=true;    

  for(int j=0;j<s;j++){
    if(left[j]!=1) continue;
    for(int n=s-1;n>=0;n--){
      for(int i=0;i<=req;i++){
        if(!dp[i][n]|| i+j+1>req) continue;
        dp[i+j+1][n+1]=true;
      }
    }
  }

  dp2[0][0]=true;    

  for(int j=0;j<s;j++){
    if(right[j]!=2) continue;
    for(int n=s-1;n>=0;n--){
      for(int i=0;i<=req;i++){
        if(dp2[i][n]==false|| i+j+1>req) continue;
        dp2[i+j+1][n+1]=true;
      }
    }
  }
ll req2=r-l;
int ans = -1;

    for(int j =1;j<=s;j++){
  for(int i =0; i<=req;i++){
      if(dp[i][j]==0 || req2-i >req) continue;
      
      if(dp2[req2-i][j]==1) {
        ans = j;
        break;
      }

    }
    if(ans!=-1) break;
  }
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
