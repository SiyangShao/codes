
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve(){
    ll n, q, p;
    cin>>n>>q>>p;
    vector<ll> a(n+n+1);
    a[0] = 0;
    for(ll i = 1; i <=n; ++i){
        cin>>a[i];
        a[i+n] = 0;
    }
    vector<ll> ans(n+1);
    vector<ll> dp;
    dp.clear();
    for(ll x = 1; x <=p ; ++x){
        dp.emplace_back(0);
        deque<pair<ll,ll>> dq;
        dq.emplace_back(dp[0],0);
        // cout<<"x="<<x<<":\n";
        for(ll k = x ; k - x<= n; k+=x){
            while(!dq.empty() && dq.front().second + p < k){
                dq.pop_front();
            }
            ll tmp = a[k] + dq.front().first;
            // cout<<k<<" "<<dq.front().second<<" "<<a[x]<<"\n";
            dp.emplace_back(tmp);
            while(!dq.empty() && dq.back().first<tmp){
                dq.pop_back();
            }
            dq.emplace_back(tmp,k);
        }
        ans[x] = dp.back();
        // cout<<ans[x]<<"\n";
    }
    while(q--){
        ll x;
        cin>>x;
        if(x>p){
            cout<<"Noob\n";
            continue;
        }
        cout<<ans[x]<<"\n";
    }
}
auto main()->int{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while(_--){
        solve();
    }
}