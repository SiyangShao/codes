#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve(){
    string s;
    cin>>s;
    ll cnt = 1;
    for(auto i : s){
        if(i>='A' && i<='Z'){
            cnt++;
        }
    }
    if(cnt<=7){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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