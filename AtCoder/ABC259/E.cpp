#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e16;
auto qpow(ll a, ll b){
    ll res = 1,  MD = 0, MB = 0;
    while(b){
        if(b & 1){
            res = res * a;
            ll M = res / MOD;
            res -= M * MOD;
            MD += MB + M;
        }
        b>>=1;
        a = a * a;
        ll M = a/MOD;
        a -= a * MOD;
        MB = MB * 2 + M;
    }
    return pair{res, MD};
}
auto mul(pair<ll,ll> a, pair<ll,ll> b){
    pair<ll,ll> ans = {a.first * b.first, a.second + b.second};
    ll M = ans.first/  MOD;
    ans.first -= M * MOD;
    ans.second += M;
    return ans;
}
auto comp(auto a, auto b){
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first > b.first;
    }
}
auto solve() {
    map<ll,pair<ll,ll>> mp;
    ll N;
    cin>>N;
    vector<vector<pair<ll,ll>>> E(N);
    for(ll i = 0 ; i < N; ++i){
        ll m;
        cin>>m;
        E[i].resize(m);
        for(auto &[p,e] : E[i]){
            cin>>p>>e;
            if(mp.find(p) == mp.end()){
                mp[p] = {e,0};
            }else{
                ll tp = mp[p].first;
                mp[p] = {max(tp,e),max(min(tp,e),mp[p].second)};
            }
        }
    }
    ll cur = -1;
    pair<ll,ll> ans = {INF,INF};
    for(ll i = 0 ; i < N; ++i){
        pair<ll,ll> now = {1,0};
        for(auto &[p,e] : E[i]){
            if(mp[p].first != e){
                continue;
            }
            now = mul(now, qpow(p,mp[p].first - mp[p].second));
        }    
        if(comp(ans,now)){
            ans = now;
            cur = i+1;
        }
    }
    cout<<cur<<"\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}