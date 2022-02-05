#include <bits/stdc++.h>
using namespace std;
long long l , k;
int main(){
    cin>>l>>k;
    if(l!=2){
        cout<<"No\n";
    }else{
        if(k==1||k==2||k==3){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}