#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    set<ll> st;
    ll r = sqrt(n);
    for (ll i = 0; i <= r; ++i) {
        st.emplace(i);
        if (i)
            st.emplace(n / i);
    }
    cout << st.size() << "\n";
    for (auto i : st) {
        cout << i << " ";
    }
    cout << "\n";
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