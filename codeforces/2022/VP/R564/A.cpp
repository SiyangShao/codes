#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll x, y, z;
    cin >> x >> y >> z;
    if (x > y + z) {
        cout << "+\n";
    } else if (y > x + z) {
        cout << "-\n";
    } else if (z == 0 && x == y) {
        cout << "0\n";
    } else {
        cout << "?\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--) {
        solve();
    }
}