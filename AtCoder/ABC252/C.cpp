#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<string> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    unsigned long long ans = LONG_LONG_MAX;
    for (ll k = 0; k <= 9; ++k) {
        unsigned long long cnt = 0;
        multiset<ll> st;
        st.clear();
        for (auto &i : a) {
            for (ll j = 0; j < 10; ++j) {
                if (i[j] - '0' == k) {
                    cnt = max(cnt, j + 10 * st.count(j));
                    st.insert(j);
                }
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
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