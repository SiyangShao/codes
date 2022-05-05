#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (x <= a) {
        if (y <= b + c) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        c += a;
        c -= x;
        if (c < 0) {
            cout << "NO\n";
        } else {
            if (y <= b + c) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
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