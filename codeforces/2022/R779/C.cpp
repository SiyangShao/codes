#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> c(n);
    ll one = 0;
    for (auto &i : c) {
        cin >> i;
        if (i == 1)
            one++;
    }
    if (one != 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (c[i] + 1 < c[(i + 1) % n]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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