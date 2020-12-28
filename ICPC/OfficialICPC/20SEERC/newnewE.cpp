#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (ll i = a; i <= n; ++i)

int main() {
    ll n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        int j;
        cin >> j;
        a[i] = j%3;
    }
    int n1[n+1];
    int n2[n+1];
    n1[0]=0;
    n2[0]=0;
    for(int i = 1; i<n+1;i++){
        n1[i]= n1[i-1] + a[i-1]==1;
        n2[i] = n2[i-1] + a[i-1]==2;
    }

    for(int )
    
    cout << ans << endl;
}