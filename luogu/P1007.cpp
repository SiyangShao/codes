#include <bits/stdc++.h>
using namespace std;
int l , n , a[5001] , mx , mi;
int main(){
    cin>>l>>n;
    for(int i = 1 ; i<= n ; i++){
        cin>>a[i];
        mx=max(mx,max(a[i],l+1-a[i]));
        mi=max(mi,min(a[i],l+1-a[i]));
    }
    cout<<mi<<" "<<mx<<"\n";
}