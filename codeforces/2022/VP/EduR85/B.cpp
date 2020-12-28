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
    sort(a.begin(), a.end(), greater<>());
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += a[i];
        if (sum / (i + 1) >= x) {
            continue;
        } else {
            cout << i << "\n";
            return;
        }
    }
    cout << n << "\n";
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