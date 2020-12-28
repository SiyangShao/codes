#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin>>n;
    vector<string> p(n);
    set<string> st, nxt;
    for(auto &i: p){
        cin>>i;
    }
    ll ans = 0;
    for(int i = 0 ; i < n; ++i){
        nxt.clear();
        for(int j = i + 1; j < n; ++j){
            nxt.emplace(p[j]);
            if(p[i]!=p[j]) continue;
            for(int k = 0 ; k <4; ++k){
                for(char x = '0' ; x <= '9' ; ++x){
                    auto pre = p[i][k];
                    p[i][k] = x;
                    if(st.contains(p[i]) || nxt.contains(p[i])){
                        
                        continue;
                    }
                }
            }
        }
        st.insert(p[i]);
    }
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