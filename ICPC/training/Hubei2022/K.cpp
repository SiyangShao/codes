#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    double n_, c;
    cin >> n >> c;
    n_ = n;
    if (n >= 10000000) {
        cout << c + 2.0 << "\n";
    } else if (n >= 9800000) {
        auto cnt = 1 + (n_ - 9800000) / 200000;
        cnt += c;
        cout << max(cnt, 0.0) << "\n";
    } else {
        auto cnt = (n_ - 9500000) / 300000;
        cnt += c;
        cout << max(cnt, 0.0) << "\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    setiosflags(ios::fixed);
    cout << fixed << setprecision(8);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}