#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
auto solve() {
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ll ans = 1;
    bool flgS = false, flagT = false;
    for(ll i = 0 ; i< n; ++i){
        ll nQ = (s[i] == '?') + (t[i] == '?');
        ll cnt = 1;
        if(nQ == 2){
            cnt = 100;
        }
    } 
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