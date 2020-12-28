#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> s(n), f(n);
    ll cur = 0;
    for (auto &i : s) {
        cin >> i;
    }
    for (auto &i : f) {
        cin >> i;
    }
    cout << f[0] - s[0];
    cur = f[0];
    for (ll i = 1; i < n; ++i) {
        cout << " ";
        if (s[i] >= cur) {
            cur = s[i];
        }
        cout << f[i] - cur;
        cur = f[i];
    }
    cout << "\n";
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