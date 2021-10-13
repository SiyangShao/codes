#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int t = i+1 ;t < n ; t++ ){
            if(a[i] > a[t]){
                int q;
                q = a[t];
                a[t] = a[i];
                a[i] = q;
            }
        }
    }
    int m = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        if(a[i]==a[i+1]){
            m++;
        }
    }
    cout<< n - m << endl;
    cout<<a[0]<<" ";
    for(int i = 1 ; i < n ; i++){
        if(a[i]!=a[i-1]){
            cout<<a[i];
        if( i == n -1){
            cout<<endl;
        }
        else{
            cout<<" ";
        }
        }
    }
    return 0;
}