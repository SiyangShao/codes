#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * @brief 
 * For step k, it will take i & i + gcd(k, n), each gcd(k,n)
 */
auto main()->int{
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  ll n;
  cin>>n;
  ll cnt = 0, bs = 0;
  for(ll i = 1; i<= n/2; ++i){
    if(n%i==0){
      cnt+=i;
      bs++;
    }
  }
  cout<<cnt<<"\n";
  cout<<bs<<"\n";
}