#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b + c || b > a + c || c > a + b || (a + b - c) % 2 != 0) {
        cout << "Impossible\n";
        return;
    }
    cout << (a + b - c) / 2 << " " << b - (a + b - c) / 2 << " "
         << a - (a + b - c) / 2 << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}
