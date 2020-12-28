#include <bits/stdc++.h>
using namespace std;
int T, n,k;
int a[110][110];
int mp[110][110];
int vis[110][110];
inline int cal(int i, int j) {
    return a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j + 1] + a[i][j - 1] +
           a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
}
inline bool reverse(){
    bool flag = true;
    int tmp;
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=n ; j++){
            tmp = cal(i,j);
            if(a[i][j]==1){
                if(tmp!=2&&tmp!=3){
                    vis[i][j] = 1;
                }else{
                    vis[i][j]=0;
                }
            }else{
                if(tmp==3){
                    vis[i][j]=1;
                }else{
                    vis[i][j]=0;
                }
            }
        }
    }
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=n ; j++){
            if(vis[i][j]){
                if(a[i][j]==1){
                    a[i][j]=0;
                }else{
                    a[i][j]=1;
                }
            }
            if(a[i][j]!=mp[i][j]){
                flag = false;
            }
        }
    }
    return flag;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=n ; j++){
                cin>>a[i][j];
                mp[i][j] = a[i][j];
                vis[i][j] = 0;
            }
        }
        bool flag = false;
        for(int i = 1 ; i<=k  ; i++){
            if(reverse()){
                cout<<"YES\n";
                flag = true;
                cout<<i<<"\n";
                break;
            }
        }
        if(!flag){
            cout<<"NO\n";
        }
    }
}