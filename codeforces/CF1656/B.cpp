#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    for (auto i = a.begin(); i < a.end(); ++i) {
        auto pos = lower_bound(i, a.end(), *i + k);
        if (pos != a.end() && *pos == *i + k) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
}