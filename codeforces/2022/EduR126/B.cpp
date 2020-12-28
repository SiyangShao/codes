#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    ll op = 15;
    ll bs = 2;
    for (ll i = 1; i <= 15; ++i) {
        if (n % bs == 0) {
            op = min(op, 15 - i);
        } else {
            auto res = n / bs;
            res++;
            op = min(op, 15 - i + res * bs - n);
        }
        bs *= 2;
    }
    cout << op << " ";
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