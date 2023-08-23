#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, x;
    cin>>n>>x;
    vector<ll> h(n * 2);
    for(auto &i:h){
        cin>>i;
    }
    sort(h.begin(),h.end());
    for(ll i = 0 ; i < n;++i){
        if(h[i+n] - h[i] < x){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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