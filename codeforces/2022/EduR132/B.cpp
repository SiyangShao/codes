#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<ll> pre(n), bck(n);
    pre[0] = 0;
    bck[n - 1] = 0;
    for (ll i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            pre[i] = pre[i - 1];
        } else {
            pre[i] = pre[i - 1] + abs(a[i] - a[i - 1]);
        }
    }
    for (ll i = n - 2; i >= 0; --i) {
        if (a[i] >= a[i + 1]) {
            bck[i] = bck[i + 1];
        } else {
            bck[i] = bck[i + 1] + abs(a[i] - a[i + 1]);
        }
    }
    while (m--) {
        ll s, t;
        cin >> s >> t;
        s--, t--;
        if (s == t) {
            cout << "0\n";
        } else if (s < t) {
            cout << pre[t] - pre[s] << "\n";
        } else {
            cout << bck[t] - bck[s] << "\n";
        }
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