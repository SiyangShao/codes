#include <bits/stdc++.h>
using namespace std;
int t , n;
int ans;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        ans = 0;
        for(int i = 1 , tmp ; i<=n ; i++){
            cin>>tmp;
            ans+=tmp;
        }
        if(ans<n){
            cout<<"1\n";
        }else{
            cout<<ans-n<<"\n";
        }
    }
}