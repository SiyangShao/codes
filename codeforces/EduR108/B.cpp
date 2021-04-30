#include <bits/stdc++.h>
using namespace std;
int t , n , m , k;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int ma = max(n,m);
        int mi = min(n,m);
        int sum = (mi-1)+(ma-1)*mi;
        int maxi = (ma-1)+(mi-1)*ma;
        if(sum<=k&&k<=maxi){
            if((k-sum)%2==0){
                cout<<"Yes\n";
            }else{
                cout<<"NO\n";
            }
        }else{
            cout<<"NO\n";
        }
    }
}