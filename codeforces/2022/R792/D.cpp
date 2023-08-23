#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
        a[i] = a[i] - (n - 1 - i);
    }
    sort(a.begin(), a.end(), greater<>());
    for (ll i = 0; i < k; ++i) {
        ans -= a[i];
    }
    ans -= (k) * (k - 1) / 2;
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