#include <bits/stdc++.h>
using namespace std;
int t , n , m;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(m==1){
            cout<<n+1<<"\n";
        }else{
            cout<<min(3,n/m+1)<<"\n";
        }
    }
}