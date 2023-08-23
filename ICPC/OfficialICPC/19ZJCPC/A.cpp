#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "0\n";
    } else if (a < b) {
        if ((b - a) % 2 == 1)
            cout << "1\n";
        else if ((b - a) / 2 % 2 == 1)
            cout << "2\n";
        else
            cout << "3\n";
    } else {
        if ((a - b) % 2 == 0)
            cout << "1\n";
        else
            cout << "2\n";
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