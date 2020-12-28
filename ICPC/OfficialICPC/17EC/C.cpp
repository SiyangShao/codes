#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 0; i <= n; ++i) {
        ll s;
        cin >> s;
        ans += s;
    }
    ll mx = 0;
    // Obvious we can find OFFSET if Ang went out at t=0, total time spent
    // waiting is 0
    ll prea = 120;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        if (a <= prea) {
            // if we went out at time a[i], we need to wait time b[i].
            prea = a;
            mx = b;
        }
    }
    ans += mx;
    cout << ans << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    ll t = 1;
    while (_--) {
        cout << "Case #" << t << ": ";
        t++;
        solve();
    }
}