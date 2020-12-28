#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010;
ll n , c , x[maxn] , a;
ll l=1 ,r,ans;
bool check(ll j){
    ll t = x[1] , num=0;
    for(int i = 2 ; i<= n ; i++){
        if(x[i]-t>=j){
            t=x[i];
        }else{
            num++;
        }
        if(num>a) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>c;
    for(int i = 1 ; i<= n ; i++){
        cin>>x[i];
    }
    sort(x+1,x+n+1);
    a=n-c;
    r = x[n]-x[1];
    while(l<=r){
        ll mid = (l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=max(ans,mid);
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<"\n";
}