#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    ll change = 0, preL = -1e16, preR = 1e16;
    for (int i = 0; i < n; ++i) {
        ll L = a[i] - x, R = a[i] + x;
        if (L > preR || R < preL) {
            change++;
            preL = L;
            preR = R;
        } else {
            preL = max(L, preL);
            preR = min(R, preR);
            assert(preL <= preR);
        }
    }
    cout << change << "\n";
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