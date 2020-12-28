#include <bits/stdc++.h>
using namespace std;
int v,n,a[30],b[20010];//01背包问题的板子是这个了
int main(){
    cin>>v>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = v ; j >= a[i] ; j--){
            b[j]=max(b[j],b[j-a[i]]+a[i]);//经典状态转移了2333
        }
    }
    cout<<v-b[v-1]<<endl;
    return 0;
}