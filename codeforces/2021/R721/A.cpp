#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        ll val =1;
        while(n){
            val*=2;
            n/=2;
        }
        val/=2;
        cout<<val-1<<"\n";
    }
}