#include <bits/stdc++.h>
using namespace std;
int _,s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>_;
    while(_--){
        cin>>s;
        if(s==2){
            cout<<"-1\n";
        }
        else if(s%2==0){
            cout<<s/2<<"\n";
        }else{
            if(s==1||s==3){
                cout<<"-1\n";
            }else{
                cout<<1+(s-3)/2<<"\n";
            }
        }
    }
}