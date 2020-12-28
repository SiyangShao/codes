#include <bits/stdc++.h>
using namespace std;
int n;
int a[2001] , _;
int main(){
    cin>>_;
    while(_--){
        cin>>n;
        vector<int> odd;
        vector<int> even;
        for(int i = 1 ; i<= n ; i++){
            cin>>a[i];
            if(a[i]%2==1){
                odd.push_back(a[i]);
            }else{
                even.push_back(a[i]);
            }
        }
        for(auto i : odd){
            cout<<i<<" ";
        }
        for(auto i : even){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}