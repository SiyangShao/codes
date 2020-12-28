#include <bits/stdc++.h>
using namespace std;
int t , a , b , c ,d;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if((a>c&&a>d&&b>c&&b>d)||(c>a&&c>b&&d>a&&d>b)){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}