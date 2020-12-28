#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto main()->int{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    vector<ll> a = {1,2,3};
    for(ll i = 0 ; i < a.size(); ++i){
        for(ll j = 0 ; j < a.size(); ++j){
            if(a[i] < a[j]){
                swap(a[i],a[j]);
            }
        }
        for(ll j = 0 ; j < a.size(); ++j){
            cout<<a[j]<<" \n"[j+1 == a.size()];
        }
    }
}