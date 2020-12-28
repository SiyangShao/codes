#include <bits/stdc++.h>
using namespace std;
int main(){
    int t , r , b , d;
    cin>>t;
    while(t--){
        cin>>r>>b>>d;
        int ma = max(r,b);
        int mi = min(r,b);
        if(ceil((ma)/double(mi))-d>1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}