#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1LL<<16;
array<ll, N> dp;
array<ll, 17> bs, a;
auto init(){
  bs[0] = 1;
  for(ll i = 1; i <= 16; ++i){
    bs[i] = bs[i-1] * 2LL;
  }
  fill(dp.begin(), dp.end(), -1);
}
void dfs(ll x){
  if(x == 0){
    dp[x] = 0;
    return;
  }
}
auto solve(){
  ll n, k;
  cin>>n>>k;
  for(ll i = 0 ; i < n; ++i){
    
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solve();
}