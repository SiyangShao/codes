#include <bits/stdc++.h>
using namespace std;
long long _ , n;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int main(){
    cin>>_;
    while(_--){
        cin>>n;
        
        if((n%2==0&&int(sqrt(n/2))*int(sqrt(n/2))==n/2)||(n%4==0&&int(sqrt(n/4))*int(sqrt(n/4))==n/4)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}