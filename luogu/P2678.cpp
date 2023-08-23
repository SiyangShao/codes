#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l , n , m , a[50010];
bool check(int x){
    int j = 0;
    int now = 0;
    int i = 0;
    while(i<n+1){
        i++;
        if(a[i]-a[now]<x){
            j++;
        }else{
            now = i;
        }
    }
    if(j>m){
        return false;
    }
    else return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>l>>n>>m;
    for(int i = 1 ; i<= n ; i++)cin>>a[i];
    a[n+1]=l;
    ll left = 0 , right = l,ans=l;
    while(left<=right){
        ll mid = (left+right)/2;
        if(check(mid)){
            ans = mid;
            left = mid+1; 
        }else{
            right = mid-1;
        }
    }
    cout<<ans<<"\n";
}