#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    ll a = 0, b = 0;
    for (auto i : s) {
        if (i == 'a') {
            if (b == 1) {
                cout << "NO\n";
                return;
            }
            b = 0;
            a++;
        } else {
            if (a == 1) {
                cout << "NO\n";
                return;
            }
            a = 0;
            b++;
        }
    }
    if (a == 1 || b == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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