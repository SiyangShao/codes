#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    bool one = false, zero = false;
    for (auto &i : a) {
        cin >> i;
        if (i == 1) {
            one = true;
        } else if (i == 0) {
            zero = true;
        }
        mp[i] = 1;
    }
    if (zero && one) {
        cout << "NO\n";
        return;
    }
    if (!zero && !one) {
        cout << "YES\n";
        return;
    }
    if (zero) {
        cout << "YES\n";
        return;
    }
    if (one) {
        for (auto i : a) {
            if (mp[i - 1] == 1) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
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