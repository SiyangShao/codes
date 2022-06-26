#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> a(n), b(m);
    ll ans = 0;
    for (auto &i : a) {
        cin >> i;
        if (i >= x) {
            ans++;
        }
    }
    for (auto &i : b) {
        cin >> i;
        if (i <= x) {
            ans++;
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