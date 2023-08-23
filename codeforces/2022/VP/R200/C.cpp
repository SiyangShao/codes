#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    while (b) {
        ans += a / b;
        swap(a, b);
        b %= a;
    }
    cout << ans << "\n";
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
