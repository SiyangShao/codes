#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m, res = 0;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end(), greater<>());
    for (ll i = 0; i + 1 < n; ++i) {
        if (i == 0) {
            res += a[i] * 2;
        } else {
            res += a[i];
        }
    }
    if (res + n <= m) {
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