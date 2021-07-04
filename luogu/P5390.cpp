#include <iostream>
#define int long long
using namespace std;
const int mod = 998244353;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,ans=1,tmp,res=0;
        cin>>n;
        for(int i = 0 ; i < n ; i++){
            if(i!=0){
                ans=(ans*2)%mod;
            }
            cin>>tmp;
            res|=tmp;
        }
        cout<<(ans*res)%mod<<"\n";
    }
}