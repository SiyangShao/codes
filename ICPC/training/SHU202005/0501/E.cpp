#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , a[500010] , b[500010];
signed main(){
    cin>>n;
    int tmp = 0;
    for(int i = 1 ; i<= n ; i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
        tmp = min(tmp , b[i]);
    }
    cout<<-tmp;
}