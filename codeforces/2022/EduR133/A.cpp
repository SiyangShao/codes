#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    if (n % 3 == 0) {
        cout << n / 3 << "\n";
    } else if (n % 3 == 1) {
        ll ans = n / 3 + 2;
        if (n % 2 == 0) {
            ans = min(ans, n / 2);
        }
        if (n > 3)
            ans = min(ans, (n / 3) - 1 + 2);
        cout << ans << "\n";
    } else {
        ll ans = (n / 3) + 1;
        if (n % 2 == 0) {
            ans = min(ans, n / 2);
        }
        cout << ans << "\n";
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