#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<string> mp(2);
    cin >> mp[0] >> mp[1];
    vector<pair<ll, ll>> st;
    ll ans = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (mp[0][i] == mp[1][i]) {
            if (mp[0][i] == '*') {
                st.emplace_back(1, 1);
                res = 0;
            } else {
                if (!st.empty())
                    res++, ans++;
            }
        } else {
            res = 0;
            if (mp[0][i] == '*') {
                st.emplace_back(1, 0);
            } else {
                st.emplace_back(0, 1);
            }
        }
    }
    ans -= res;
    ll l = 1, r = 1;
    ans += st.size() - 1;
    for (auto &[up, down] : st) {
        if (up == 1 && down == 1) {
            ans++;
            l = 1, r = 1;
        } else {
            if (up == 1 && l == 0) {
                l = 1, r = 1;
                ans++;
            } else if (down == 1 && r == 0) {
                l = 1, r = 1;
                ans++;
            } else if (up == 1 && l == 1) {
                r = 0;
            } else if (down == 1 && r == 1) {
                l = 0;
            }
        }
    }
    cout << ans << "\n";

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