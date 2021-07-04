#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e9;
int f[100];
int cnt;
void init(){
    f[0] = 2;
    for(cnt = 1 ; ; cnt++){
        f[cnt] = f[cnt-1] * 4;
        if(f[cnt]>maxn){
            break;
        }
    }
}
int t , n;
signed main(){
    init();
    cin>>t;
    while(t--){
        cin>>n;
        bool flag = true;
        for(int i = 0 ; i <=cnt ; i++){
            if(n == f[i]){
                cout<<"Bob\n";
                flag = false;
                break;
            }
        }
        if(flag){
            if(__builtin_ctz(n)){
                cout<<"Alice\n";
            }else{
                cout<<"Bob\n";
            }
        }
    }
}