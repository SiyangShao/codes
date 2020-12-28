#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7 , maxn = 1e16+7,cnt=41;
int a[50];
inline void pre(){
    a[0]=a[1]=1;
    for(int j = 1 ; j < cnt ; ++j){
        for(int i = 1 ; i<=j ; ++i){
            if(a[j-1]*i%j==0){
                a[j]=a[j-1]*i;
                break;
            }
        }
    }
}
signed main(){
    int _,n;
    pre();
    scanf("%lld",&_);
    while(_--){
        scanf("%lld",&n);
        int ans = 0;
        for(int i = 0 ; i < cnt && a[i] <= n ; ++i){
            ans += n/a[i];
            ans %= mod;
        }
        printf("%lld\n",ans);
    }
}