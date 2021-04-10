#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long f[10000010];
int main(){
    f[0]=1;
    for(int i = 1 ; i<= 10000000 ; i++){
        f[i] = f[i-1]*i%mod;
    }
    int q;
    cin>>q;
    while(q--){
        int a,b,c,d , q1 ,q2;
        cin>>a>>b>>c>>d;
        if(f[b]<f[a-1]){
            q1 = f[b]*mod/f[a-1];
        }else{
            q1 = f[b]/f[a-1];
        }
        if(f[d]<f[c-1]){
            q2 = f[d]*mod/f[c-1];
        }else{
            q2=f[d]/f[c-1];
        }
        cout<<q1<<" "<<q2;
        if(q2%q1==0){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}