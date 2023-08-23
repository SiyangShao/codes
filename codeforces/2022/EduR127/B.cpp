#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    auto judge = [&](ll pos) -> bool {
        auto p = pos + a[0];
        p++;
        for (int i = 1; i < n; ++i) {
            if (abs(a[i] - p) <= 1) {
                p++;
            } else {
                return false;
            }
        }
        return true;
    };
    if (judge(-1) || judge(1) || judge(0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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