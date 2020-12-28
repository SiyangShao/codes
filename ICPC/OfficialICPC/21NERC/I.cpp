#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto scan(int x, int y) {
    cout << "SCAN " << x << " " << y << endl;
    int tmp;
    cin >> tmp;
    return tmp;
}
auto dig(int x, int y) {
    cout << "DIG " << x << " " << y << endl;
    int tmp;
    cin >> tmp;
    return tmp;
}
auto solve() {
    int n, m;
    cin >> n >> m;
    auto a = scan(1, 1);
    auto b = scan(1, m);
    auto x_p = (a + b + 6 - 2 * m) / 2;
    auto y_q = (a + 4 - x_p);
    auto xxx = scan(x_p / 2, 1);
    auto yyy = scan(1, y_q / 2);
    auto p = (2 + a - xxx) / 2;
    auto x = x_p - p;
    auto q = (2 + a - yyy) / 2;
    auto y = y_q - q;
    auto z = dig(x, y);
    if (z == 1) {
        dig(p, q);
    } else {
        dig(x, q);
        dig(p, y);
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