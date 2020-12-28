#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b;
    cin >> a >> b;
    if (a == 0) {
        cout << 1 << "\n";
    } else if (b == 0) {
        cout << a + 1 << "\n";
    } else {
        cout << b * 2 + a + 1 << "\n";
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