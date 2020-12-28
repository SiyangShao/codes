#include <bits/stdc++.h>
using namespace std;
int _ , n , m;
string s , ans;
int main(){
    cin>>_;
    while(_--){
        cin>>n>>m>>s;
        ans = s;
        m = min(n,m);
        while(m--){
            int x = 0;
            if(ans[0]=='0'&&ans[1]=='1'){
                x++;
                s[0] ='1';
            }
            if(ans[n-1]=='0'&&ans[n-2]=='1'){
                x++;
                s[n-1]='1';
            }
            for(int i = 0 ; i < n ; i++){
                if(ans[i]=='0'&&((ans[i-1]=='1'&&ans[i+1]=='0')||(ans[i-1]=='0'&&ans[i+1]=='1'))){
                    s[i]='1';
                    x++;
                }
            }
            ans = s;
            if(x==0){
                break;
            }
        }
        cout<<ans<<"\n";
    }
}