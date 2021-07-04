#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , k;
int ans;
int tmp;
signed main(){
    cin>>n>>k;
    for(int i = 1 ; i<=k ; i++){
        int a, b;
        cin>>a>>b;
        ans+=b;
        tmp+=a*b;
        tmp%=n;
    }
    if(ans<n){
        cout<<"1\n";
    }else if(ans>n){
        cout<<"-1\n";
    }else{
        if(tmp == ((1+n)*n/2)%n){
            cout<<"1\n";
        }else{
            cout<<"-1\n";
        }
    }
}