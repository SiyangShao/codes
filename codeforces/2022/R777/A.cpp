#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    if(n%3 == 0){
        int t = n/3;
        for(int i = 1; i<=t; ++i){
            cout<<"21";
        }
        cout<<"\n";
    }else if(n%3 == 1){
        int t = n/3;
        for(int i = 1; i<=t; ++i){
            cout<<"12";
        }
        cout<<"1\n";
    }else{
        int t = n/3;
        for(int i = 1; i<=t; ++i){
            cout<<"21";
        }
        cout<<"2\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int _ = 1;
    cin>>_;
    while(_--){
        solve();
    }
}