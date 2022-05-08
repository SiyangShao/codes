#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> p(n), a;
    for (auto &i : p) {
        cin >> i;
    }
    ll sum = 0;
    a.assign(n, 0);
    for (ll b = 0; b < n; ++b) {
        ll d = 0;
        for (ll c = n - 1; c > b; --c) {
            sum += a[c] * d;
            if (p[c] < p[b]) {
                d++;
            } else {
                a[c]++;
            }
        }
    }
    cout << sum << "\n";
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