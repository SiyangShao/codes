#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        cout << "0\n";
    } else if (a + b + c + d <= 3) {
        cout << "1\n";
    } else {
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