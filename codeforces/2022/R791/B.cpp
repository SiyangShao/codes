#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    ll sum = 0;
    set<ll> mp;
    for (auto &i : a) {
        cin >> i;
        sum += i;
    }
    for (ll i = 0; i < n; ++i) {
        mp.insert(i);
    }
    ll pre = 0;
    while (q--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll x, v;
            cin >> x >> v;
            x--;
            if (mp.find(x) != mp.end()) {
                sum = sum - a[x] + v;
            } else {
                sum = sum - pre + v;
                mp.insert(x);
            }
            a[x] = v;
        } else {
            ll x;
            cin >> x;
            pre = x;
            mp.clear();
            sum = x * n;
        }
        cout << sum << "\n";
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