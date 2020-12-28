#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto main()->int{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll n;
    cin>>n;
    vector<string> mp(n);
    for(auto &i: mp){
        cin>>i;
    }
    auto output = mp;
    for(ll i = n-1; i>=0; --i){
        for(ll j = i+1; j < n; ++j){
            assert(mp[i][j] == '1' || mp[i][j] == '0');
            if(mp[i][j] == '1'){
                output[i][j] = '1';
            }else{
                output[i][j] = '0';
            }
        }
        for(ll j = n-1; j > i; --j){
            if(output[i][j] == '1'){
                for(ll k = 0; k < i; ++k){
                    ll r = mp[k][j] - '0', l = mp[k][i] - '0';
                    if(r < l){
                        r += 10;
                    }
                    r -= l;
                    mp[k][j] = r + '0';
                }
            }
        }
    }
    for(auto &i: output){
        cout<<i<<"\n";
    }
}