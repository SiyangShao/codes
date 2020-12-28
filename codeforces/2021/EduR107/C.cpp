#include <bits/stdc++.h>
using namespace std;
int n , q;
int a[51] , t , m;
int main(){
    memset(a,0x3f,sizeof(a));
    cin>>n>>q;
    for(int i = 1 , tmp ; i<= n ; i++){
        cin>>tmp;
        a[tmp]=min(a[tmp],i);
        m = max(m,tmp);
    }
    while(q--){
        cin>>t;
        cout<<a[t]<<" ";
        int tmp = a[t];
        for(int i = 1 ; i<= m ; i++){
            if(a[i]<tmp){
                a[i]++;
            }
        }
        a[t]=1;
    }
}