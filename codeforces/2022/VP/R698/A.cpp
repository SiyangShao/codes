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
    ll bs = a[0];
    k -= bs;
    for (auto &i : a) {
        i -= bs;
    }
    ll res = 0;
    for (auto i : a) {
        res = gcd(res, i);
    }
    if (k % res == 0) {
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