#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, C;
    cin >> n >> C;
    vector<ll> attack(C + 1);
    for (ll i = 0, c, d, h; i < n; ++i) {
        cin >> c >> d >> h;
        attack[c] = max(attack[c], d * h);
    }
    for (ll i = 1; i <= C; ++i) {
        attack[i] = max(attack[i], attack[i - 1]);
        for (ll j = 1; i * j <= C; ++j) {
            attack[i * j] = max(attack[i * j], attack[i] * j);
        }
    }
    ll m;
    cin >> m;
    while (m--) {
        ll D, H;
        cin >> D >> H;
        auto pos = upper_bound(attack.begin(), attack.end(), D * H);
        if (pos == attack.end()) {
            cout << "-1 ";
        } else {
            cout << pos - attack.begin() << " ";
        }
    }
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