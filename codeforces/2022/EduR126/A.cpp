#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    ll ans = 0;
    for (ll i = 1; i < n; ++i) {
        ans += min(abs(a[i - 1] - a[i]) + abs(b[i - 1] - b[i]),
                   abs(a[i - 1] - b[i]) + abs(b[i - 1] - a[i]));
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