#include <bits/stdc++.h>
using namespace std;
string s,b;
char a;
int t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>s;
        a = 'z';
        for(auto i : s){
            if(i <= a){
                a = i;
            }
        }
        b="";
        bool flag = false;
        for(auto i : s){
            if(i!=a || flag){
                b+=i;
            }else if(i == a){
                flag = true;
            }
        }
        cout<<a<<" "<<b<<"\n";
    }
}