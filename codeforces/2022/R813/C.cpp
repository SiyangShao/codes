#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    set<ll> zero, nw;
    nw.emplace(a[0]);
    for (ll i = 1; i < n; ++i) {
        if (zero.contains(a[i])) {
            a[i] = 0;
        }
        if (a[i] >= a[i - 1]) {
            nw.emplace(a[i]);
            continue;
        }
        zero.insert(nw.begin(), nw.end());
        nw.clear();
        if (zero.contains(a[i])) {
            a[i] = 0;
        }
        nw.emplace(a[i]);
    }
    if (zero.contains(0)) {
        cout << zero.size() - 1 << "\n";
    } else {
        cout << zero.size() << "\n";
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