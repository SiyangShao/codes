#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    cout<<n/2+1<<"\n";
    for(int i = 1 ; i<= n ; i+=2){
        cout<<i<<" ";
    }
    if(n%2==0){
        cout<<n;
    }
}