#include <bits/stdc++.h>
using namespace std;
int t , n , tmp;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        bool flag = true;
        for(int i = 1 ; i<= n ;i++){
            cin>>tmp;
            if(int(sqrt(tmp))!=sqrt(tmp)){
                flag = false;
            }
        }
        if(flag){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}
