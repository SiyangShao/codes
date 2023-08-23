#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &i:a){
        cin>>i;
    }
    sort(a.begin(), a.end());
    vector<ll> ans;
    ll L = 0, R = n-1;
    while(L <= R){
        ans.emplace_back(L);
        if(L!=R){
            ans.emplace_back(R);
            R--;
        }
        L++;
    }
    reverse(ans.begin(), ans.end());
    for(auto &i:ans){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}