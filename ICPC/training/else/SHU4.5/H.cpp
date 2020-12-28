#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
    long long n, k;
    cin>>n>>k;
    for(int i = 2 ; i< n ; i++){
        memset(a,0,sizeof(a));
        a[1]=1;
        for(int j = 2 ; j<= n ; j++){
            a[j]=a[j-1];
            if(j>i){
                a[j]+=a[j-i];
            }
            if(j%7==0){
                a[j]+=a[j/7];
            }
        }
        if(a[n]==k){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
}