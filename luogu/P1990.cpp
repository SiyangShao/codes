#include <bits/stdc++.h>
using namespace std;
int f[1000001],g[1000001];
int main(){
    int n;
    cin>>n;
    f[0] = 1;
    f[1] = g[1] = 1;
    for(int i = 1 ;  i<=n ; i++){
        f[i] = (f[i-1]+f[i-2]+2*g[i-2])%10000;
        g[i] = (g[i-1]+f[i-1])%10000;
    }
    cout<<f[n]<<endl;
}