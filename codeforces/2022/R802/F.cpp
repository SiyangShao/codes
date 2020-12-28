#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector a(vector<vector<ll>>(2, vector<ll>(n))),
        b(vector<vector<ll>>(2, vector<ll>(n)));
    for (auto &i : a) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    for (auto &i : b) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    if (accumulate(a[0].begin(), a[0].end(), 0) +
            accumulate(a[1].begin(), a[1].end(), 0) !=
        accumulate(b[0].begin(), b[0].end(), 0) +
            accumulate(b[1].begin(), b[1].end(), 0)) {
        cout << "-1\n";
        return;
    }
    ll ans = 0;
    vector<ll> bs(4, 0);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 2; ++j) {
            ans += bs[j] + bs[j + 2];
            if (a[j][i])
                bs[j]++;
            if (b[j][i])
                bs[j + 2]++;
            auto x = min(bs[j], bs[j + 2]);
            bs[j] -= x, bs[j + 2] -= x;
        }
        for (ll j = 0; j < 2; ++j) {
            auto x = min(bs[j], bs[3 - j]);
            ans += x;
            bs[j] -= x, bs[3 - j] -= x;
        }
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