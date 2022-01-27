#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        int L = n , R = 0;
        for(auto &i:a){
            cin>>i;
            L = min(L,i);
            R = max(R,i);
        }
        int dif = R - L;
        

    }
}