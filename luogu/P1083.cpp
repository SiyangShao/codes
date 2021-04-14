#include <bits/stdc++.h>
#define int long long
using namespace std;
int b , p , k;
int qpow(int b , int p){
    int ans = 1 , base = b;
    while(p>0){
        if(p&1){
            ans*=base;
            ans%=k;
        }
        base*=base;
        base%=k;
        p>>=1;
    }
    return ans%k;
}
signed main(){
    scanf("%lld%lld%lld",&b,&p,&k);
    int ans = qpow(b,p);
    printf("%lld^%lld mod %lld=%lld\n",b,p,k,ans);
}