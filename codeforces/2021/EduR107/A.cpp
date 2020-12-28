#include <bits/stdc++.h>
using namespace std;
int _ , n ;
int main(){
    cin>>_;
    while(_--){
        cin>>n;
        int ans = 0;
        for(int i=1 , tmp ; i<= n ; i++){
            cin>>tmp;
            if(tmp==1||tmp==3){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}