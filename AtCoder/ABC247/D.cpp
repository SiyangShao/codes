#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    queue<pair<ll, ll>> Q;
    ll q;
    cin >> q;
    while (q--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll x, c;
            cin >> x >> c;
            Q.emplace(x, c);
        } else {
            ll c;
            cin >> c;
            ll ans = 0;
            while (!Q.empty() && Q.front().second <= c) {
                c -= Q.front().second;
                ans += Q.front().first * Q.front().second;
                Q.pop();
            }
            if (c != 0 && !Q.empty()) {
                Q.front().second -= c;
                ans += c * Q.front().first;
            }
            cout << ans << "\n";
        }
    }
}
auto main() -> int {
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}