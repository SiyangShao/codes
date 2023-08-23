#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int t,n;
int a[200010];
signed main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        int mx = 0, cmx = 0, k = 0;
        int ans = 1, sub = 1;
        for(int i = 1 ; i<=n ; ++i){
            scanf("%lld",&a[i]);
            mx = max(mx,a[i]);
        }
        for(int i = 1 ; i<=n ; ++i){
            if(a[i]==mx){
                cmx++;
            }else if(a[i] == mx-1){
                k++;
            }
        }
        for(int i = 1 ; i<=n ; ++i){
            ans = ans*i %MOD;
            if(i!= k+1){
                sub = sub*i %MOD;
            }
        }
        if(cmx == 1){
            ans = (ans-sub+MOD) % MOD;
        }
        printf("%lld\n",ans);
    }
}