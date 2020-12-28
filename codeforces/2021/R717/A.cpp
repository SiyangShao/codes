#include <bits/stdc++.h>
using namespace std;
int _ , n , k;
int a[101];
int main(){
    cin>>_;
    while(_--){
        cin>>n>>k;
        int o = k;
        for(int i = 1 ; i< n ; i++){
            cin>>a[i];
            if(a[i]>0&&k>0){
                int tmp=min(a[i],k);
                a[i]-=tmp;
                k-=tmp;
            }
            cout<<a[i]<<" ";
        }
        cin>>a[n];
        a[n]+=o-k;
        cout<<a[n]<<"\n";
    }
}