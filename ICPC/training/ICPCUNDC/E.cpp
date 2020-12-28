#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> E(n);
    for(ll i = 1; i < n; ++i){
        ll u, v;
        cin>> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    vector<ll> pos(n, -1);
    pos.assign(n,-1);
    deque<ll> d;
    function<void(int)> dfs = [&](int u){
        if(E[u].size()%2==1){
            for(auto v: E[u]){
                if(pos[v] != -1) continue;
                pos[v] = 1;
                d.emplace_back(v);
                dfs(v);
            }
        }else{
            if(pos[u] == 0){
                ll sum = E[u].size() / 2;
                for(auto v :E[u]){
                    if(pos[v]!=-1) continue;
                    if(sum){
                        sum--;
                        pos[v] = 0;
                        d.emplace_front(v);
                        dfs(v);
                    }else{
                        pos[v] = 1;
                        d.emplace_back(v);
                        dfs(v);
                    }
                }
            }else{
                ll sum = E[u].size()/2;
                for(auto v: E[u]){
                    if(pos[v]!=-1) continue;
                    if(sum){
                        sum--;
                        pos[v] = 1;
                        d.emplace_back(v);
                        dfs(v);
                    }else{
                        pos[v] = 0;
                        d.emplace_front(v);
                        dfs(v);
                    }
                }
            }
        }
    };
    pos[0] = 0;
    d.emplace_back(0);
    dfs(0);
    while(!d.empty()){
        cout<<d.front()<<" ";
        d.pop_front();
    }
}
auto main()->int{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while(_--){
        solve();
    }
}