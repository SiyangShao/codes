#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll k;
    cin >> k;
    if (k < 60) {
        if (k < 10)
            cout << "21:0" << k;
        else
            cout << "21:" << k;
    } else {
        k -= 60;
        if (k < 10)
            cout << "22:0" << k;
        else
            cout << "22:" << k;
    }
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