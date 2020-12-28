#include <bits/stdc++.h>
using namespace std;
int t ;
string s;
int main(){
    cin>>t;
    while(t--){
        cin>>s;
        int x = -1;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i]=='1'){
                if(i<s.length()&&s[i+1]=='0'){
                    continue;
                }
                x = i;
                break;
            }
        }
        if(x==-1){
            cout<<"YES\n";
        }else{
            bool flag = false;
            for(int i = x+1 ; i < s.length() ; i++){
                if(s[i]=='0'){
                    if(i+1<s.length()&&s[i+1]=='0'){
                        cout<<"NO\n";
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag){
                cout<<"YES\n";
            }
        }
    }
}