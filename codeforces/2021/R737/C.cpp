#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
int binpow(int a , int b){
    int res = 1;
    while(b){
        if(b&1){
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}
int _ , n , k;
signed main(){
    scanf("%lld",&_);
    while(_--){
        scanf("%lld %lld",&n,&k);
        int ans = 0;
        if(k==0){
            printf("1\n");
        }else if(n == 1){
            printf("%lld\n",binpow(2,k));
        }else if (n&1){
            ans = binpow(2,n-1)+1;
            ans = binpow(ans, k);
            printf("%lld\n",ans);
        }else{
            int t = binpow(2,n-1)-1 , last = 1;
            for(int i = k ; i>0 ; --i){
                ans = ans + (last * binpow(2,(i-1)*n)%mod)%mod;
                last = last*t%mod;
            }
            ans = (ans+last)%mod;
            printf("%lld\n",ans);
        }
    }
}