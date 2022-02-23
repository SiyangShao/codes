#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
string s ;
int m , _ ;
int f[200010] ;
int judge(int x , int y){
    if(y==0) return 1;
    if(x+y<10){
        return 1;
    }
    if(x+y<=18){
        return 2;
    }
    if(x+y==19) return 3;
    if(x+y<=27) return 4;
    if(x+y==28) return 5;
    if(x+y==29) return 7;
    if(x+y==30) return 8;
    if(f[y-(10-x)]==0){
        f[y-(10-x)] = judge(1,y-10+x)+judge(0,y-10+x);
        f[y-(10-x)]%=mod;
    }
    return f[y-(10-x)];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>_;
    judge(9,200000);
    while(_--){
        cin>>s>>m;
        int dp = 0;
        for(int i = 0 ; i < s.length() ; i++){
            int qs = s[i]-'0';
            dp += judge(qs,m);
            dp%=mod;
        }
        cout<<dp<<"\n";
    }
}