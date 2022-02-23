#include <bits/stdc++.h>
using namespace std;
int t , n , k1 , k2 , w , b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k1>>k2>>w>>b;
        if((k1+k2<w+w)||(n+n-k1-k2<b+b)){
            cout<<"NO\n";
        }else{
            w -= min(k1,k2);
            w -= abs(k1-k2)/2;
            b -= min(n-k1 , n-k2);
            b -= abs((n-k1)-(n-k2))/2;
            if(w<=0&&b<=0){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}