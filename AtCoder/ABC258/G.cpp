#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 3010;
auto solve() {
    ll n;
    cin >> n;
    vector<bitset<N>> bit(n);
    vector<string> mp(n);
    for (auto &i : mp) {
        cin >> i;
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (mp[i][j] == '1') {
                bit[i][j] = true;
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (mp[i][j] == '1') {
                ans += (bit[i] & bit[j]).count();
            }
        }
    }
    cout << ans / 6 << "\n";
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