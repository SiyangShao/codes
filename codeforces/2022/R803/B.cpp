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
    if (k == 1) {
        cout << (n - 1) / 2 << "\n";
        return;
    }
    ll cnt = 0;
    for (ll i = 1; i + 1 < n; ++i) {
        if (a[i] > a[i - 1] + a[i + 1]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
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
