#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + n), b(n + n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        a[i + n] = a[i], b[i + n] = b[i];
    }
    auto c = a;
    for (ll i = 1; i < n * 2; ++i) {
        a[i] -= b[i - 1];
        if (a[i] < 0) {
            a[i] = 0;
        }
    }
    ll bs = 0;
    for (ll i = 0; i < n; ++i) {
        bs += a[i];
    }
    ll ans = bs;
    for (ll i = 0; i < n; ++i) {
        bs += a[i + n];
        bs -= c[i];
        bs -= a[i + 1];
        bs += c[i + 1];
        // cout<<bs<<" ";
        ans = min(ans, bs);
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