#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b;
    cin >> a >> b;
    string s = "";
    if (a == b) {
        for (ll i = 0; i < a; ++i) {
            cout << "01";
        }
        cout << "\n";
    } else if (a > b) {
        ll L = (a - b + 1) / 2, R = (a - b) / 2;
        for (ll i = 0; i < R; ++i) {
            cout << "0";
        }
        for (ll i = 0; i < b; ++i) {
            cout << "01";
        }
        for (ll i = 0; i < L; ++i) {
            cout << "0";
        }
        cout << "\n";
    } else {
        ll L = (b - a + 1) / 2, R = (b - a) / 2;
        for (ll i = 0; i < R; ++i) {
            cout << "1";
        }
        for (ll i = 0; i < a; ++i) {
            cout << "10";
        }
        for (ll i = 0; i < L; ++i) {
            cout << "1";
        }
        cout << "\n";
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