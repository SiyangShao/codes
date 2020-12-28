#include <bits/stdc++.h>
#define int long long
using namespace std;
int _ , n , m;
signed main(){
    cin>>_;
    while(_--){
        cin>>n>>m;
        int ans = n-n/m;
        if(n%m){
            ans++;
        }
        if(ans%2!=1){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }
    }
}