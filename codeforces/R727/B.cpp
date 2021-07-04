#include <bits/stdc++.h>
using namespace std;
int n , q ;
string s;
int num[100010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q>>s;
    for(int i = 1 ; i<=n ; i++){
        num[i] = num[i-1] + s[i-1] - 'a'+1;
    }
    while(q--){
        int l , r;
        cin>>l>>r;
        cout<<num[r] - num[l-1] <<"\n"; 
    }
}