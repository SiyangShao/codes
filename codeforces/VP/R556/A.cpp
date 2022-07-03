#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m, r;
    cin >> n >> m >> r;
    vector<ll> s(n), b(m);
    for (auto &i : s) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    auto s_l = *min_element(s.begin(), s.end()),
         b_r = *max_element(b.begin(), b.end());
    if (s_l >= b_r) {
        cout << r << "\n";
    } else {
        cout << (r % s_l) + (r / s_l) * b_r << "\n";
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