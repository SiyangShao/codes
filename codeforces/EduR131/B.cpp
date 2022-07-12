#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin>>n;
    cout<<"2\n";
    vector<ll> vis(n+1);
    vis.assign(n+1,0);
    for(ll i = 1; i<=n; ++i){
        if(vis[i]) continue;
        ll cur = i;
        while(cur <= n && !vis[cur]){
            vis[cur] = 1;
            cout<<cur<<" ";
            cur*=2;
        }
    }
    cout<<"\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}