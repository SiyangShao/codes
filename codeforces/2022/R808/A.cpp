#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), choose(n);
    ll x = 0;
    for (auto &i : a) {
        cin >> i;
    }
    for (ll i = n - 1; i >= 0; --i) {
        if (a[i] <= x) {
            choose[i] = 1;
        } else if (x < q) {
            x++;
            choose[i] = 1;
        } else {
            choose[i] = 0;
        }
    }
    for (auto &i : choose) {
        cout << i;
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