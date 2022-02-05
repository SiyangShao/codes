#include <bits/stdc++.h>
using namespace std;
string s , a;
int main(){
    cin>>s>>a;
    int k = 0;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i]==a[k]){
            k++;
        }
        if(k==a.length()){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
}