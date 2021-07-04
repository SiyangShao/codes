#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , m;
    cin>>n>>m;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    while(m--){
        next_permutation(a,a+n);//全排列函数2333
    }
    for(int i = 0 ; i < n ; i++){
        cout<<a[i];
        if(i!=n-1){
            cout<<" ";
        }
        else{
            cout<<endl;
        }
    }
    return 0;
}