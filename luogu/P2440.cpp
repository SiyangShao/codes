#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , k , l , r=100000005;
ll a[100000005];
inline bool judge(ll x){
    ll sum = 0;
    if(x==0){
        return true;
    }
    for(ll i = 1 ; i<= n ; i++){
        sum+=a[i]/x;
    }
    if(sum>=k){
        return true;
    }else{
        return false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(ll i = 1; i<= n ; i++){
        cin>>a[i];
    }
    ll mid,answer=0;
    while(l<=r){
        mid = (l+r)/2;
        if(judge(mid)){
            l=mid+1;
            answer=max(answer,mid);
        }else{
            r=mid-1;
        }
    }
    cout<<answer<<"\n";
}