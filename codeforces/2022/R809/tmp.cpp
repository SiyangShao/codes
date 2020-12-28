#include <bits/stdc++.h>
using namespace std;
auto solve() {
    for(int i = 1; i < 100; ++i){
        set<int> st;
        for(int j = 1; j <= i+1; ++j){
            st.insert(i/j);
        }
        cout<<i<<", "<<st.size()<<": ";
        for(auto i : st){
            cout<<i<<" ";
        }
        cout<<"\n";
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