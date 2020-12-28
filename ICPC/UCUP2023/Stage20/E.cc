#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
//#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
bool isSquare(ll x) {
    ll tmp = (ll)sqrt(x);
    return tmp * tmp == x;
}
auto solve() {
    ll R = 0;
    cin >> R;
    vector<pair<int, int>> x;
    for (ll i = 0; i * i <= R; ++i) {
        if (R - i * i) {
            if (isSquare(R - i * i)) {
                x.emplace_back(i, (ll)sqrt(R - i * i));
            }
        }
    }
    if (x.empty()) {
        cout << "inf\n";
    } else {
        ll ans = 0;
        for (auto [l, r] : x) {
            ans = gcd(ans, l * l + r * r);
            ans = gcd(ans, abs(l * l - r * r));
        }
        cout << ans << "\n";
    }
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