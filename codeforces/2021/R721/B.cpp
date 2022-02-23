#include <bits/stdc++.h>
using namespace std;
string s;
int t , n;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>s;
        int cnt = 0;
        for(auto i : s){
            if(i=='0'){
                cnt++;
            }
        }
        if(cnt==1){
            cout<<"BOB\n";
        }else if(cnt%2==1){
            cout<<"ALICE\n";
        }else{
            cout<<"BOB\n";
        }
    }
}