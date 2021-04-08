#include <bits/stdc++.h>
using namespace std;
int n , sum,tmp,ans=-1000;
int main(){
    cin>>n;
    while(n--){
        cin>>tmp;
        sum+=tmp;
        ans=max(ans,sum);
        if(sum<0){
            sum=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}