#include <bits/stdc++.h>
using namespace std;
long long n , c , ans;
int main(){
    cin>>n>>c;
    long long a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i = 0 ; i <= n ; i++){
        ans += ((upper_bound(a,a+n,a[i]+c))-a)-(lower_bound(a,a+n,a[i]+c)-a);
    }
    cout<<ans<<endl;
    return 0;
}