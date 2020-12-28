#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main(){
    cin>>t;
    while(t--){
        cin>>s;
        string a = 'a'+s , b = s+'a';
        string a1 = a , b1 = b;
        reverse(a1.begin(),a1.end());
        reverse(b1.begin() , b1.end());
        if(a1!=a){
            cout<<"YES\n";
            cout<<a<<"\n";
        }else if(b1!=b){
            cout<<"YES\n";
            cout<<b<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
}