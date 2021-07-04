#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n , m;
int l ,r;
int a[100005];
inline bool judge(int x){
    int tot=0,num=0;
    for(int i = 1 ; i<= n ; i++){
        if(tot+a[i]<=x){
            tot+=a[i];
        }else{
            tot=a[i];
            num++;
        }
    }
    return num>=m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1 ; i<= n ; i++){
        cin>>a[i];
        r+=a[i];
        l=max(l,a[i]);
    }
    while(l<=r){
        int mid = l+r>>1;
        if(judge(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
}