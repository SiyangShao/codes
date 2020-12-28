#include <bits/stdc++.h>
using namespace std;
int t , m , n;
int a[101] , b[101];
int main(){
    cin>>t;
    while(t--){
        cin>>m>>n;
        for(int i = 0 ; i < m ; i++){
            cin>>a[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin>>b[i];
        }
        if(m>n){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }
}