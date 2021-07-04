#include <bits/stdc++.h>
using namespace std;
int n , f[250][250],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1 ; i<= n ; i++) cin>>f[i][i];
    for(int len = 1 ; len<= n ; len++){
        for(int i = 1 ; i<= n ; i++){
            int j = len+i - 1;
            for(int k = i ; k< j && k < n ; k++){
                if(f[i][k]==f[k+1][j]){
                    f[i][j]=max(f[i][j],f[i][k]+1);
                    ans=max(ans,f[i][k]+1);
                }
            }
        }
    }
    cout<<ans<<"\n";
}