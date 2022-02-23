#include <bits/stdc++.h>
using namespace std;
int t , n;
int a[101];
int ans;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 1 ; i<=n ; ++i){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        ans = a[n];
        for(int i = 1 ; i<n ; ++i){
            ans&=a[i];
        }
        cout<<ans<<"\n";
    }

}