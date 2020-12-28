#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    ll ans = 0;
    ll beg = 0;
    while (beg < n && a[beg] == 0) {
        beg++;
    }
    for (ll i = beg; i + 1 < n; ++i) {
        if (a[i] > 0) {
            ans += a[i];
        }
        if (a[i] == 0) {
            ans++;
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