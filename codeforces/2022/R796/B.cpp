#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> siz(40);
    ll even = 0;
    for (auto &i : siz) {
        i = 0;
    }
    for (auto &i : a) {
        cin >> i;
        ll cnt = 0;
        while (i % 2 == 0) {
            cnt++;
            i /= 2;
        }
        siz[cnt]++;
    }
    for (ll i = 0; i < 40; ++i) {
        if (siz[i] != 0) {
            if (i == 0) {
                cout << n - siz[i] << "\n";
            } else {
                cout << i + n - 1 << "\n";
            }
            return;
        }
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