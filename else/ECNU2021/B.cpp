#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int a[20];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>s;
        int n = s.length();
        int sum = n;
        for(int i = 0 ; i < n; ++i){
            a[i+1] = s[i] - '0';
        }
    }
}