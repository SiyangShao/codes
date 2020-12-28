#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , t[200010] , d[200010];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int time = 0;
    for(int i = 1 ; i<= n ; i++){
        cin>>t[i]>>d[i];
        if(time<t[i]){
            time=t[i];
        }
        time+=d[i];
    }
    cout<<time;
}