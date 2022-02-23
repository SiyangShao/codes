#include <bits/stdc++.h>
using namespace std;
#define int  long long
typedef long long ll;
int t , n;
const int mo = 2050;
signed main(){
    cin>>t;
    while(t--){
        cin>>n;
        if(n%2050!=0){
            cout<<"-1\n";
        }else{
            int x = n/2050;
            int sum = 0;
            while(x){
                sum+=x%10;
                x/=10;
            }
            cout<<sum<<"\n";
        }
    }
}