#include <bits/stdc++.h>
// 我真的没想到这个暴力都能过......
#define ll long long
using namespace std;
inline ll cal(ll x){
    ll j = x , tmp = 0;
    while(j!=0){
        tmp+=j%10;
        j/=10;
    }
    return tmp;
}
int main(){
    int t = 1;
    ll n;
    cin>>t;
    while(t--){
        cin>>n;
        while(__gcd(n,cal(n))==1){
            n++;
        }
        cout<<n<<"\n";
    }
}