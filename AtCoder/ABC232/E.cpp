#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
long long binpow(long long a, long long b, long long m = mod) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int H,W,K;
    int x1,y1,x2,y2;
    cin>>H>>W>>K>>x1>>y1>>x2>>y1;
    if(K==0){
        if(x1==x2&&y1==y2){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(K%2 == 1){
        if(x1==x2 && y1==y2){
            cout<<0;
        }else if(x1==x2){

        }else if(y1==y2){

        }else{
            cout<<0;
        }
    }
}