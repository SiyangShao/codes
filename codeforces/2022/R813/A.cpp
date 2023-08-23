#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
        i--;
    }
    ll ans = 0;
    for (ll i = 0; i < k; ++i) {
        if (a[i] >= k) {
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