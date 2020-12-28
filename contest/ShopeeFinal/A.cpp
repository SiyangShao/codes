#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
auto add(ll x) {
    auto ret = 1;
    while (x % 2 == 0) {
        x /= 2;
        ret *= 2;
    }
    return ret;
}
auto solve() {
    cin >> n;
    auto tmp = 1LL;
    while (tmp <= n) {
        tmp *= 2;
    }
    if (tmp == n + 1) {
        cout << "1\n";
    } else {
        cout << "0\n";
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