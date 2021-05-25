#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int a[1000010] , d[1000010] , num[1000010] , tot , p[1000010] , v[1000010];
int n;
int sum=1 , ans=0;
void pre() {
    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!v[i]) v[i] = 1, p[++tot] = i, d[i] = 2, num[i] = 1;
        for (int j = 1; j <= tot && i <= n / p[j]; ++j) {
            v[p[j] * i] = 1;
            if (i % p[j] == 0) {
                num[i * p[j]] = num[i] + 1;
                d[i * p[j]] = (d[i] / num[i * p[j]] * (num[i * p[j]] + 1))%mod;
                break;
            } else {
                num[i * p[j]] = 1;
                d[i * p[j]] = (d[i] * 2)%mod;
            }
        }
    }
}
signed main(){
    cin>>n;
    pre();
    for(int i = 2 ; i<=n ; i++){
        a[i]=1;
        ans=d[i];
        a[i]%=mod;
        ans+=sum;
        sum+=ans;
        ans%=mod;
        sum%=mod;
    }
    if(n==1){
        cout<<"1\n";
        return 0;
    }
    cout<<ans;
}